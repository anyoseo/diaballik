#include "game.h"
Game::Game(): current(PlayerColor::RED),opponent(PlayerColor::BLUE),selected{nullptr}, leftMoves{2}, hasThrow{true}
{
}

void Game::initialize(){
    for(unsigned i=0;i<board.getBoard().size();i++){
    board.put(Piece(PlayerColor::RED,false),Position(0,i));
    board.put(Piece(PlayerColor::BLUE,false),Position(this->board.getBoard().size()-1,i));
    board.put(Piece(PlayerColor::RED,true),Position(0,5));
    board.put(Piece(PlayerColor::BLUE,true),Position(this->board.getBoard().size()-1,5));
    }
}

void Game::initializeVariante(){
    for(unsigned i=0;i<board.getBoard().size();i++){
    board.put(Piece(PlayerColor::RED,false),Position(0,i));
    board.put(Piece(PlayerColor::BLUE,false),Position(this->board.getBoard().size()-1,i));
    board.put(Piece(PlayerColor::RED,false),Position(this->board.getBoard().size()-1,1));
    board.put(Piece(PlayerColor::BLUE,false),Position(0,1));
    board.put(Piece(PlayerColor::RED,true),Position(0,5));
    board.put(Piece(PlayerColor::BLUE,true),Position(this->board.getBoard().size()-1,5));
    }
}

bool Game::isOppositeSide(){
    if(current.getColor()==PlayerColor::BLUE){
        for(unsigned i=0;i<board.getBoard().size();i++){
            if(board.isMyOwn(Position(0,i),current.getColor()) && board.getPiece(Position(0,i)).getHasBall()){
                return true;
            }
        }
    }else{
        for(unsigned j=0;j<board.getBoard().size();j++){
            if(board.isMyOwn(Position((static_cast<unsigned>(this->board.getBoard().size())-1),j),current.getColor())
                    && board.getPiece(Position((static_cast<unsigned>(this->board.getBoard().size())-1),j)).getHasBall()){
                return true;
            }
    }
}
    return false;
}

void Game::movePiece(Move move){

    if(this->leftMoves==0){
            throw "Tous les deplacements autorises ont ete effectue.";
    }else{
        unsigned mouvement=0;
        if(move.getEnd().getColumn()>move.getStart().getColumn() && move.getEnd().getRow()==move.getStart().getRow()){
            mouvement=move.getEnd().getColumn()-move.getStart().getColumn();
        }else if(move.getEnd().getColumn()<move.getStart().getColumn() && move.getEnd().getRow()==move.getStart().getRow()){
            mouvement=move.getStart().getColumn()-move.getEnd().getColumn();
        }else if(move.getEnd().getColumn()==move.getStart().getColumn() && move.getEnd().getRow()<move.getStart().getRow()){
            mouvement=move.getStart().getRow()-move.getEnd().getRow();
        }else if(move.getEnd().getColumn()==move.getStart().getColumn() && move.getEnd().getRow()>move.getStart().getRow()){
            mouvement=move.getEnd().getRow()-move.getStart().getRow();
        }else{
            mouvement=2;
        }

        board.remove(move.getStart());
        board.put(move.getPiece(),move.getEnd());
        leftMoves-=mouvement;
    }
    if(leftMoves==0&&!hasThrow){
        switchPlayer();
    }

}

void Game::throwBall(Position position){
    if(!hasThrow)
        throw "Vous avez deja effectue le lance de ball.";

    Position ballPosition=Position(0,0);

    for (unsigned row = 0; row < this->board.getBoard().size(); ++row) {
        for (unsigned column = 0; column < this->board.getBoard().size(); ++column) {
            if(this->board.getPiece(Position(row, column)).getHasBall()&&this->board.getPiece(Position(row, column)).getColor()==this->current.getColor())
             ballPosition=Position(row, column);
        }
    }
    board.getPiece(ballPosition).removeBall();
    board.getPiece(position).giveBall();
    this->hasThrow=false;
    if(leftMoves==0&&!hasThrow){
        switchPlayer();
    }
}

void Game::switchPlayer(){
    Player temp=this->current;
    this->current=this->opponent;
    this->opponent=temp;
    this->hasThrow=true;
    this->leftMoves=2;
}

std::vector<Move> Game::getMoves(Position position){
    if(!board.isInside(position)){
        throw "La position ne se trouve pas dans les limites du pateau de jeu.";
    }
    if(this->board.isFree(position)){
        throw "La case est vide.";
    }
    if(this->board.getPiece(position).getHasBall()){
        throw "La piece qui est selectionne ne peut pas bouger car elle posede la balle.";
    }
    if(this->board.getPiece(position).getColor()!=this->current.getColor()){
        throw "La piece selectionne ne vous appartient pas.";
    }
    if(this->leftMoves==0){
        throw "Il ne reste plus de mouvement possible.";
    }
    std::vector<Move> moves;
        if(board.isInside(position.next(Direction::UP)) && board.isFree(position.next(Direction::UP))){
            moves.push_back(Move(position,position.next(Direction::UP),board.getPiece(position)));
        }
        if(board.isInside(position.next(Direction::DOWN)) && board.isFree(position.next(Direction::DOWN))){
            moves.push_back(Move(position,position.next(Direction::DOWN),board.getPiece(position)));
        }
        if(board.isInside(position.next(Direction::RIGHT)) && board.isFree(position.next(Direction::RIGHT))){
            moves.push_back(Move(position,position.next(Direction::RIGHT),board.getPiece(position)));
        }
        if(board.isInside(position.next(Direction::LEFT)) && board.isFree(position.next(Direction::LEFT))){
            moves.push_back(Move(position,position.next(Direction::LEFT),board.getPiece(position)));
        }

    if(this->leftMoves==2){

        if((board.isInside(position.next(Direction::LEFT)) && board.isFree(position.next(Direction::LEFT)))&&
                (board.isInside(position.next(Direction::LEFT).next(Direction::LEFT)) && board.isFree(position.next(Direction::LEFT).next(Direction::LEFT)))){
            moves.push_back(Move(position,position.next(Direction::LEFT).next(Direction::LEFT),board.getPiece(position)));
        }
        if((board.isInside(position.next(Direction::RIGHT)) && board.isFree(position.next(Direction::RIGHT)))&&
                (board.isInside(position.next(Direction::RIGHT).next(Direction::RIGHT)) && board.isFree(position.next(Direction::RIGHT).next(Direction::RIGHT)))){
            moves.push_back(Move(position,position.next(Direction::RIGHT).next(Direction::RIGHT),board.getPiece(position)));
        }
        if((board.isInside(position.next(Direction::DOWN)) && board.isFree(position.next(Direction::DOWN)))&&
                (board.isInside(position.next(Direction::DOWN).next(Direction::DOWN)) && board.isFree(position.next(Direction::DOWN).next(Direction::DOWN)))){
            moves.push_back(Move(position,position.next(Direction::DOWN).next(Direction::DOWN),board.getPiece(position)));
        }
        if((board.isInside(position.next(Direction::UP)) && board.isFree(position.next(Direction::UP)))&&
                (board.isInside(position.next(Direction::UP).next(Direction::UP)) && board.isFree(position.next(Direction::UP).next(Direction::UP)))){
            moves.push_back(Move(position,position.next(Direction::UP).next(Direction::UP),board.getPiece(position)));
        }
        if(board.isInside(position.next(Direction::DOWN_LEFT)) && board.isFree(position.next(Direction::DOWN_LEFT))){
            moves.push_back(Move(position,position.next(Direction::DOWN_LEFT),board.getPiece(position)));
        }
        if(board.isInside(position.next(Direction::DOWN_RIGHT)) && board.isFree(position.next(Direction::DOWN_RIGHT))){
            moves.push_back(Move(position,position.next(Direction::DOWN_RIGHT),board.getPiece(position)));
        }
        if(board.isInside(position.next(Direction::UP_LEFT)) && board.isFree(position.next(Direction::UP_LEFT))){
            moves.push_back(Move(position,position.next(Direction::UP_LEFT),board.getPiece(position)));
        }
        if(board.isInside(position.next(Direction::UP_RIGHT)) && board.isFree(position.next(Direction::UP_RIGHT))){
            moves.push_back(Move(position,position.next(Direction::UP_RIGHT),board.getPiece(position)));
        }
    }

    return moves;
}

bool Game::antiGame(){
    unsigned blockRed=0;
    unsigned blockBlue=0;
    for(unsigned row=0; row<this->board.getBoard().size(); row++){
        for (unsigned column = 0; column < board.getBoard().size(); ++column) {
            Position posi=Position(row, column);
            if(!this->board.isFree(posi)){
                if(this->current.getColor()==PlayerColor::RED && this->board.isInside(posi.next(Direction::DOWN))&&this->board.isMyOwn(posi, PlayerColor::RED)){
                    if(((!this->board.isInside(posi.next(Direction::DOWN_RIGHT)))||this->board.isMyOwn(posi.next(Direction::DOWN_RIGHT), PlayerColor::BLUE))&&this->board.isMyOwn(posi.next(Direction::DOWN), PlayerColor::BLUE)
                                                &&((!this->board.isInside(posi.next(Direction::DOWN_LEFT)))||this->board.isMyOwn(posi.next(Direction::DOWN_LEFT), PlayerColor::BLUE))){
                       blockRed++;
                    }
                }else if(this->current.getColor()==PlayerColor::BLUE && this->board.isInside(posi.next(Direction::UP))&&this->board.isMyOwn(posi, PlayerColor::BLUE)){
                    if(((!this->board.isInside(posi.next(Direction::UP_RIGHT)))||this->board.isMyOwn(posi.next(Direction::UP_RIGHT), PlayerColor::RED))&&this->board.isMyOwn(posi.next(Direction::UP), PlayerColor::RED)
                                                &&((!this->board.isInside(posi.next(Direction::UP_LEFT)))||this->board.isMyOwn(posi.next(Direction::UP_LEFT), PlayerColor::RED))){
                        blockBlue++;
                    }
                }
            }
        }
    }
    if(blockRed>2||blockBlue>2){
        return true;
    }
    return false;
}


std::vector<Position> Game::getThrows(){
    if(this->hasThrow==false)
        throw "Vous ne pouvez plus lancer la balle.";

    Position position=Position(0,0);

    for (unsigned row = 0; row < this->board.getBoard().size(); ++row) {
        for (unsigned column = 0; column < this->board.getBoard().size(); ++column) {
            if(this->board.getPiece(Position(row, column)).getHasBall()&&this->board.getPiece(Position(row, column)).getColor()==this->current.getColor())
             position=Position(row, column);
        }
    }

    if(!this->board.getPiece(position).getHasBall())
        throw "La piece n'a pas la balle.";

    std::vector<Position> throws;
    bool stop=false;
    for(unsigned i=1;!stop; i++){//Verticale bas
        if(this->board.isInside(Position(position.getRow()+i, position.getColumn()))){
            if(!this->board.isFree(Position(position.getRow()+i, position.getColumn()))){
                if(this->board.isMyOwn(Position(position.getRow()+i, position.getColumn()), this->current.getColor())){
                    throws.push_back(Position(position.getRow()+i, position.getColumn()));
                }else{
                    stop=true;
                }
            }
        }else{
            stop=true;
        }
    }
    stop=false;
    for(unsigned i=1;!stop; i++){//Horizontale droite
        if(this->board.isInside(Position(position.getRow(), position.getColumn()+i))){
            if(!this->board.isFree(Position(position.getRow(), position.getColumn()+i))){
                if(this->board.isMyOwn(Position(position.getRow(), position.getColumn()+i), this->current.getColor())){
                    throws.push_back(Position(position.getRow(), position.getColumn()+i));
                }else{
                    stop=true;
                }
            }
        }else{
            stop=true;
        }
    }
    stop=false;
    for(unsigned i=1;!stop; i++){//Horizontale gauche
        if(this->board.isInside(Position(position.getRow(), position.getColumn()-i))){
            if(!this->board.isFree(Position(position.getRow(), position.getColumn()-i))){
                if(this->board.isMyOwn(Position(position.getRow(), position.getColumn()-i), this->current.getColor())){
                    throws.push_back(Position(position.getRow(), position.getColumn()-i));
                }else{
                    stop=true;
                }
            }
        }else{
            stop=true;
        }
    }
    stop=false;
    for(unsigned i=1;!stop; i++){//verticale haut
        if(this->board.isInside(Position(position.getRow()-i, position.getColumn()))){
            if(!this->board.isFree(Position(position.getRow()-i, position.getColumn()))){
                if(this->board.isMyOwn(Position(position.getRow()-i, position.getColumn()), this->current.getColor())){
                    throws.push_back(Position(position.getRow()-i, position.getColumn()));
                }else{
                    stop=true;
                }
            }
        }else{
            stop=true;
        }
    }
    stop=false;
    for(unsigned i=1;!stop; i++){//Diagonale haut droite
        if(this->board.isInside(Position(position.getRow()-i, position.getColumn()+i))){
            if(!this->board.isFree(Position(position.getRow()-i, position.getColumn()+i))){
                if(this->board.isMyOwn(Position(position.getRow()-i, position.getColumn()+i), this->current.getColor())){
                    throws.push_back(Position(position.getRow()-i, position.getColumn()+i));
                }else{
                    stop=true;
                }
            }
        }else{
            stop=true;
        }
    }
    stop=false;
    for(unsigned i=1;!stop; i++){//Diagonale haut gauche
        if(this->board.isInside(Position(position.getRow()-i, position.getColumn()-i))){
            if(!this->board.isFree(Position(position.getRow()-i, position.getColumn()-i))){
                if(this->board.isMyOwn(Position(position.getRow()-i, position.getColumn()-i), this->current.getColor())){
                    throws.push_back(Position(position.getRow()-i, position.getColumn()-i));
                }else{
                    stop=true;
                }
            }
        }else{
            stop=true;
        }
    }
    stop=false;
    for(unsigned i=1;!stop; i++){//Diagonale bas droite
        if(this->board.isInside(Position(position.getRow()+i, position.getColumn()+i))){
            if(!this->board.isFree(Position(position.getRow()+i, position.getColumn()+i))){
                if(this->board.isMyOwn(Position(position.getRow()+i, position.getColumn()+i), this->current.getColor())){
                    throws.push_back(Position(position.getRow()+i, position.getColumn()+i));
                }else{
                    stop=true;
                }
            }
        }else{
            stop=true;
        }
    }
    stop=false;
    for(unsigned i=1;!stop; i++){//Diagonale bas gauche
        if(this->board.isInside(Position(position.getRow()+i, position.getColumn()-i))){
            if(!this->board.isFree(Position(position.getRow()+i, position.getColumn()-i))){
                if(this->board.isMyOwn(Position(position.getRow()+i, position.getColumn()-i), this->current.getColor())){
                    throws.push_back(Position(position.getRow()+i, position.getColumn()-i));
                }else{
                    stop=true;
                }
            }
        }else{
            stop=true;
        }
    }
    return throws;
}



#include "controller.h"


Controller::Controller(Game& game):game{game}
{
}

void Controller::startGame(){
    displayWelcome();
    std::string command="";
    while(!std::regex_match(command,std::regex("simple"))&&!std::regex_match(command,std::regex("variante"))){
        command=askVariante();
    }
    if(std::regex_match(command,std::regex("variante")))
        game.initializeVariante();
    else
        game.initialize();
    displayBoard();
    gestionCommand();
}

void Controller::gestionCommand(){
    std::string command="";
    std::vector<Move> moves;
    std::vector<Position> throws;
    while(!(std::regex_match(command,std::regex("exit"))||this->game.isWin())){
        std::vector<std::string> tokens;
        displayLeftMoves();
        command=this->askCommand();
        tokenisation(tokens,command);
        if(!std::regex_match(command,std::regex(""))){
            if(std::regex_match(tokens[0],std::regex("moves"))){
                moves=applyMoves(tokens);
            }else if(std::regex_match(tokens[0],std::regex("move"))){
                applyMove(std::stoul(tokens[1]), moves);
            }else if(std::regex_match(tokens[0],std::regex("throws"))){
                throws=applyThrows();
            }else if(std::regex_match(tokens[0],std::regex("throw"))){
                try{
                    this->game.throwBall(throws.at(std::stoul(tokens[1])));
                } catch (const char* msg) {
                    std::cerr << msg << std::endl;
                }
            }else if(std::regex_match(tokens[0],std::regex("help"))){
                displayHelp();
            }
            if(this->game.endHand()||(std::regex_match(command,std::regex("end")))){
                this->game.switchPlayer();
                displaySwitchEnd(this->game.getCurrentPlayer().getColor());
            }
            this->displayBoard();
        }
    }
}

void Controller::applyMove(unsigned index, std::vector<Move> moves){
    if(index>moves.size()-1){
        std::cout<<"Move incorrect."<<std::endl;
    }else{
    try{
    this->game.movePiece(moves.at(index));
    moves.clear();
    } catch (const char* msg) {
    std::cerr << msg << std::endl;
}
    }
}

std::vector<Move> Controller::applyMoves(std::vector<std::string> &tokens){
    std::vector<Move> moves;
    try {
        moves = this->game.getMoves(Position(std::stoul(tokens[1]), std::stoul(tokens[2])));
        diplayMoves(moves);
    } catch (const char* msg) {
        std::cerr << msg << std::endl;
    }
    return moves;
}

std::vector<Position> Controller::applyThrows(){
    std::vector<Position> throws;
    try{
        throws = this->game.getThrows();
        displayThrows(throws);
    } catch (const char* msg) {
        std::cerr << msg << std::endl;
    }
    return throws;
}

void Controller::displayBoard(){
    std::cout<<""<<std::endl;
    std::cout<<" ";
    for(unsigned k=0; k<game.getGameBoard().size(); k++){
        std::cout<<"|"<<k;
    }
    std::cout<<"|"<<std::endl;
    for(unsigned i=0; i<game.getGameBoard().size(); i++){
        std::cout<<i;
        for(unsigned j=0; j<this->game.getGameBoard().at(i).size(); j++){
            std::cout<<"|";
            if(this->game.getGameBoard()[i][j].getColor()==PlayerColor::BLUE||this->game.getGameBoard()[i][j].getColor()==PlayerColor::RED){
                if(this->game.getGameBoard()[i][j].getColor()==PlayerColor::RED && !game.getGameBoard()[i][j].getHasBall()){
                    std::cout<<"R";
                }else if(this->game.getGameBoard()[i][j].getColor()==PlayerColor::BLUE && !game.getGameBoard()[i][j].getHasBall()){
                    std::cout<<"B";
                }else if(this->game.getGameBoard()[i][j].getColor()==PlayerColor::BLUE && game.getGameBoard()[i][j].getHasBall()){
                    std::cout<<"*";
                }else if(this->game.getGameBoard()[i][j].getColor()==PlayerColor::RED && game.getGameBoard()[i][j].getHasBall()){
                    std::cout<<"&";
                }
            }else{
                std::cout<<" ";
            }
        }
        std::cout<<"|"<<std::endl;
    }

    std::cout<<""<<std::endl;
}

std::string Controller::askCommand(){
    std::string cmd;
    std::cout<<"\nEntrez une commande : ";
    std::getline(std::cin, cmd);
    std::cout<<""<<std::endl;
    return cmd;
}

std::string Controller::askVariante(){
    std::string cmd;
    std::cout<<"\nEntrez 'simple' ou 'variante' selon le type de partie que vous voulez jouer : ";
    std::getline(std::cin, cmd);
    std::cout<<""<<std::endl;
    return cmd;
}

void Controller::tokenisation(std::vector<std::string> &tokens,std::string command){

        std::stringstream cmdStream(command);
        std::string intermediate;
        while(getline(cmdStream, intermediate, ' '))
        {
            tokens.push_back(intermediate);
        }
}

void Controller::displayWelcome(){
    std::cout<<"Bienvenue dans Diaballik"<<std::endl;
    std::cout<<"========================\n"<<std::endl;
    std::cout<<"Tapez 'help' pour voir les commandes"<<std::endl;
}

void Controller::displaySwitchEnd(PlayerColor color){
    std::cout<<"Au joueur ";
    if(color==PlayerColor::RED){
        std::cout<<"rouge ";
    }else{
        std::cout<<"bleu ";
    }
    std::cout<<"de jouer."<<std::endl;
}

void Controller::diplayMoves(std::vector<Move> moves){
    int index=0;
    std::cout<<"Voici les mouvements possibles : \n"<<std::endl;
    for(auto& move:moves){
        std::cout << " [" << index <<"] "<< move.getEnd().getRow() << "-" <<move.getEnd().getColumn()<< std::endl;
        index++;
    }
}

void Controller::displayThrows(std::vector<Position> positions){
    std::cout<<"Il y a "<< positions.size()<<" lancés de balle position :\n"<<std::endl;
    for (unsigned i=0;i<positions.size();i++) {
        std::cout<< " ["<< i <<"] x = "<< positions.at(i).getRow()<<", y = "<< positions.at(i).getColumn()<<std::endl;
    }
}

void Controller::displayLeftMoves(){
    std::cout<<"Il vous reste "<<game.getLeftMoves()<<" mouvement(s) et ";
    if(game.getHasThrow()==true){
        std::cout<<"1 lance"<<std::endl;
    }else{
        std::cout<<"0 lance"<<std::endl;
    }
}

void Controller::displayHelp(){
    std::cout<<"Voici les commandes possibles :\n"<<std::endl;
    std::cout<<" [1] 'moves [x] [y]' : pour connaitre le(s) mouvement(s) possible(s) d'un pion."<<std::endl;
    std::cout<<" [2] 'move [numero du move]' : pour effectuer un mouvement."<<std::endl;
    std::cout<<" [3] 'throws' : pour connaître le(s) lance(s) de balle possible."<<std::endl;
    std::cout<<" [4] 'throw [numero du throw]' : pour lancer la balle a un pion"<<std::endl;
    std::cout<<" [5] 'end' : pour passer la main."<<std::endl;
    std::cout<<" [6] 'exit' : pour quitter le jeu."<<std::endl;
}

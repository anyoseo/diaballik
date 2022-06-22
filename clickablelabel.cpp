#include "clickablelabel.h"


ClickableLabel::ClickableLabel(QWidget* parent, Qt::WindowFlags flag,unsigned row, unsigned column)
    : QLabel(parent) {
    row_ = row;
    column_ = column;
    game_=nullptr;
    piece=nullptr;
}

ClickableLabel::~ClickableLabel() {}

void ClickableLabel::update(){
    reset();
    setPiece();
    isAMove();
    isAThrowSquare();
}

void ClickableLabel::mousePressEvent(QMouseEvent* event) {

    setPiece();
    setSelected();
}

void ClickableLabel::setSelected(){

    if(!game_->hasThrow()){
    if(this->piece->getHasBall()&&piece->getColor()==game_->getCurrentPlayerColor()){
        if(!game_->hasThrow())
            game_->setThrow();
    }else
        if(isThrowable){
            game_->throwBall(Position(row_, column_));
            isThrowable=false;
        }
     }


    if(game_->leftMoves()>0&&(!this->piece->getHasBall())){
        if(piece->getColor()==game_->getCurrentPlayerColor()){
            try{
                game_->setMove(Position(row_, column_));
            } catch (const char* msg) {
                std::cerr << msg << std::endl;
            }
    }
        if(isSelected==true){
        isSelected=false;
        }else{
            if(isMovable==true){
                game_->move(Position(row_, column_));
            }else{
                isSelected=true;

            }
        }
    }

}

void ClickableLabel::setRowColumn(unsigned row, unsigned column){
    row_=row;
    column_=column;
    if((row_+column_)%2!=0)
        this->setStyleSheet("QLabel { background-color: red }");
}

void ClickableLabel::setPiece(){
    piece=&this->game_->getBoard()[row_][column_];
    squareDesign();
}

void ClickableLabel::squareDesign(){
        if(this->piece->getColor()==PlayerColor::RED && !piece->getHasBall()){
            hasRedPiece();
        }else if(this->piece->getColor()==PlayerColor::BLUE && !piece->getHasBall()){
            hasBluePiece();
        }else if(this->piece->getColor()==PlayerColor::BLUE && piece->getHasBall()){
            hasBlueBallPiece();
        }else if(this->piece->getColor()==PlayerColor::RED && piece->getHasBall()){
            hasRedBallPiece();
        }else{
            this->setPixmap(QPixmap());
        }
}

void ClickableLabel::isAMove(){
    bool isOnTheList=false;
    std::vector<Move> moves = game_->getMoves();
    for (int i=0;i<moves.size();i++) {
        if((moves.at(i).getEnd().getRow()==row_)&&(moves.at(i).getEnd().getColumn()==column_)){
            movesAvailable();
            isMovable=true;
            isOnTheList=true;
        }
    }
    if(!isOnTheList)
        isMovable=false;
}

void ClickableLabel::isAThrowSquare(){
    bool isOnTheList=false;
    std::vector<Position> throws = game_->getThrows();
    for (int i=0;i<throws.size();i++) {
        if((throws.at(i).getRow()==row_)&&(throws.at(i).getColumn()==column_)){
            throwsAvailable();
            isThrowable=true;
            isOnTheList=true;
        }
    }
    if(!isOnTheList)
        isThrowable=false;
}


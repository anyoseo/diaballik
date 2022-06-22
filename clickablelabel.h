#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>
#include <QWidget>
#include <Qt>
#include "piece.h"
#include "gamefacade.h"
#include <iostream>

class ClickableLabel : public QLabel, public Observer {
    Q_OBJECT

    unsigned row_;
    unsigned column_;
    GameFacade* game_;
    Piece* piece;
    bool isSelected = false;
    bool isMovable = false;
    bool isThrowable = false;

public:
    /**
     * @brief ClickableLabel Constructor of the class ClickableLabel.
     * @param parent the parent widget.
     * @param f the signal for the click.
     * @param row the row for the label.
     * @param column the column for the label.
     */
    explicit ClickableLabel(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags(),
                            unsigned row=0,unsigned column=0);
    ~ClickableLabel();

    /**
     * @brief update Method for the update of the Observer.
     */
    void update();

    /**
     * @brief setGame Method which sets the game.
     */
    inline void setGame(GameFacade&);

    /**
     * @brief setRowColumn Method which sets the color for the background of the label depending on his cordinate.
     */
    void setRowColumn(unsigned, unsigned);


private:
    /**
     * @brief squareDesign Method which creates and puts the image of the corresponding piece on the label.
     */
    void squareDesign();

    /**
     * @brief setPiece Method which sets the piece on the label and load his image.
     */
    void setPiece();

    /**
     * @brief movesAvailable Method which displays the available moves for the piece.
     */
    inline void movesAvailable();

    /**
     * @brief hasRedPiece Method which loads the red piece.
     */
    inline void hasRedPiece();

    /**
     * @brief hasRedPiece Method which loads the blue piece.
     */
    inline void hasBluePiece();

    /**
     * @brief hasRedPiece Method which loads the red ball piece.
     */
    inline void hasRedBallPiece();

    /**
     * @brief hasRedPiece Method which loads the blue ball piece.
     */
    inline void hasBlueBallPiece();

    /**
     * @brief reset Method which resets the color of the label's background.
     */
    inline void reset();

    /**
     * @brief isAMove Method which activates and shows the labels to move to for the selected piece's movement.
     */
    void isAMove();

    /**
     * @brief setSelected Method which selects the piece and shows the possible moves or make a move depending of the action.
     */
    void setSelected();

    /**
     * @brief isAThrowSquare Method which shows and activates the labels to throw the ball to.
     */
    void isAThrowSquare();

    /**
     * @brief throwsAvailable Method which shows the available labels to throw the ball to.
     */
    inline void throwsAvailable();


protected:
    /**
     * @brief mousePressEvent Method which executes the action when the label is pressed.
     * @param event the mouse click.
     */
    void mousePressEvent(QMouseEvent* event);

};

void ClickableLabel::reset(){
    if((row_+column_)%2!=0)
        this->setStyleSheet("QLabel { background-color: red }");
    else
        this->setStyleSheet("");
}

void ClickableLabel::setGame(GameFacade& game){
    game_=&game;
    game_->addObs(*this);
    setPiece();
}


void ClickableLabel::hasRedPiece(){
    QPixmap pix(":/ressources/image/redPlayer.png");
    this->setPixmap(pix.scaled(80,80,Qt::KeepAspectRatio));
}

void ClickableLabel::hasBluePiece(){
    QPixmap pix(":/ressources/image/bluePlayer.png");
    this->setPixmap(pix.scaled(80,80,Qt::KeepAspectRatio));
}

void ClickableLabel::hasRedBallPiece(){
    QPixmap pix(":/ressources/image/redBall.png");
    this->setPixmap(pix.scaled(80,80,Qt::KeepAspectRatio));
}

void ClickableLabel::hasBlueBallPiece(){
    QPixmap pix(":/ressources/image/blueBall.png");
    this->setPixmap(pix.scaled(80,80,Qt::KeepAspectRatio));
}

void ClickableLabel::movesAvailable(){
    this->setStyleSheet("QLabel { background-color: white }");
}

void ClickableLabel::throwsAvailable(){
    this->setStyleSheet("QLabel { background-color: yellow }");
}

#endif // CLICKABLELABEL_H

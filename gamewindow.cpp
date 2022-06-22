#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QPixmap>


GameWindow::GameWindow(QWidget *parent, bool mode) :
    QDialog(parent),
    game_(mode ? GameFacade(true) : GameFacade(false)),ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(1200, 800));
    game_.addObs(*this);
    lblCurrentPlayer();
    lblLeftMoves();
    lblLeftThrows();
    connection();
    initializeBoard();
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::lblCurrentPlayer(){
    if(game_.getCurrentPlayerColor()==PlayerColor::RED){
         ui->playerTurn->setText(QString::fromStdString("ROUGE"));
    }else{
        ui->playerTurn->setText(QString::fromStdString("BLEU"));
    }
}

void GameWindow::lblLeftMoves(){
    ui->leftMoves->setText(QString::number(game_.leftMoves()));
}

void GameWindow::lblLeftThrows(){
    ui->leftThrows->setText(QString::number(!game_.hasThrow()));
}

void GameWindow::initializeBoard(){
    for (unsigned i=0;i<this->board.size();i++) {
        for (unsigned j=0;j<this->board.at(i).size();j++) {
            this->board[i][j]->setGame(game_);
        }
    }
}

void GameWindow::connection(){
    connect(ui->giveHandButton,&QAbstractButton::clicked,this,&GameWindow::giveHand);
    setSquare();
    loadLabel();
}

void GameWindow::setSquare(){
    ui->lab00->setRowColumn(0, 0);
    ui->lab01->setRowColumn(0, 1);
    ui->lab02->setRowColumn(0, 2);
    ui->lab03->setRowColumn(0, 3);
    ui->lab04->setRowColumn(0, 4);
    ui->lab05->setRowColumn(0, 5);
    ui->lab06->setRowColumn(0, 6);
    ui->lab07->setRowColumn(0, 7);
    ui->lab10->setRowColumn(1, 0);
    ui->lab11->setRowColumn(1, 1);
    ui->lab12->setRowColumn(1, 2);
    ui->lab13->setRowColumn(1, 3);
    ui->lab14->setRowColumn(1, 4);
    ui->lab15->setRowColumn(1, 5);
    ui->lab16->setRowColumn(1, 6);
    ui->lab17->setRowColumn(1, 7);
    ui->lab20->setRowColumn(2, 0);
    ui->lab21->setRowColumn(2, 1);
    ui->lab22->setRowColumn(2, 2);
    ui->lab23->setRowColumn(2, 3);
    ui->lab24->setRowColumn(2, 4);
    ui->lab25->setRowColumn(2, 5);
    ui->lab26->setRowColumn(2, 6);
    ui->lab27->setRowColumn(2, 7);
    ui->lab30->setRowColumn(3, 0);
    ui->lab31->setRowColumn(3, 1);
    ui->lab32->setRowColumn(3, 2);
    ui->lab33->setRowColumn(3, 3);
    ui->lab34->setRowColumn(3, 4);
    ui->lab35->setRowColumn(3, 5);
    ui->lab36->setRowColumn(3, 6);
    ui->lab37->setRowColumn(3, 7);
    ui->lab40->setRowColumn(4, 0);
    ui->lab41->setRowColumn(4, 1);
    ui->lab42->setRowColumn(4, 2);
    ui->lab43->setRowColumn(4, 3);
    ui->lab44->setRowColumn(4, 4);
    ui->lab45->setRowColumn(4, 5);
    ui->lab46->setRowColumn(4, 6);
    ui->lab47->setRowColumn(4, 7);
    ui->lab50->setRowColumn(5, 0);
    ui->lab51->setRowColumn(5, 1);
    ui->lab52->setRowColumn(5, 2);
    ui->lab53->setRowColumn(5, 3);
    ui->lab54->setRowColumn(5, 4);
    ui->lab55->setRowColumn(5, 5);
    ui->lab56->setRowColumn(5, 6);
    ui->lab57->setRowColumn(5, 7);
    ui->lab60->setRowColumn(6, 0);
    ui->lab61->setRowColumn(6, 1);
    ui->lab62->setRowColumn(6, 2);
    ui->lab63->setRowColumn(6, 3);
    ui->lab64->setRowColumn(6, 4);
    ui->lab65->setRowColumn(6, 5);
    ui->lab66->setRowColumn(6, 6);
    ui->lab67->setRowColumn(6, 7);
    ui->lab70->setRowColumn(7, 0);
    ui->lab71->setRowColumn(7, 1);
    ui->lab72->setRowColumn(7, 2);
    ui->lab73->setRowColumn(7, 3);
    ui->lab74->setRowColumn(7, 4);
    ui->lab75->setRowColumn(7, 5);
    ui->lab76->setRowColumn(7, 6);
    ui->lab77->setRowColumn(7, 7);

}

void GameWindow::loadLabel(){
    QVector<ClickableLabel*> v;
    v.push_back(ui->lab00);
    v.push_back(ui->lab01);
    v.push_back(ui->lab02);
    v.push_back(ui->lab03);
    v.push_back(ui->lab04);
    v.push_back(ui->lab05);
    v.push_back(ui->lab06);
    v.push_back(ui->lab07);
    board.push_back(v);

    v.clear();
    v.push_back(ui->lab10);
    v.push_back(ui->lab11);
    v.push_back(ui->lab12);
    v.push_back(ui->lab13);
    v.push_back(ui->lab14);
    v.push_back(ui->lab15);
    v.push_back(ui->lab16);
    v.push_back(ui->lab17);
    board.push_back(v);

    v.clear();
    v.push_back(ui->lab20);
    v.push_back(ui->lab21);
    v.push_back(ui->lab22);
    v.push_back(ui->lab23);
    v.push_back(ui->lab24);
    v.push_back(ui->lab25);
    v.push_back(ui->lab26);
    v.push_back(ui->lab27);
    board.push_back(v);

    v.clear();
    v.push_back(ui->lab30);
    v.push_back(ui->lab31);
    v.push_back(ui->lab32);
    v.push_back(ui->lab33);
    v.push_back(ui->lab34);
    v.push_back(ui->lab35);
    v.push_back(ui->lab36);
    v.push_back(ui->lab37);
    board.push_back(v);

    v.clear();
    v.push_back(ui->lab40);
    v.push_back(ui->lab41);
    v.push_back(ui->lab42);
    v.push_back(ui->lab43);
    v.push_back(ui->lab44);
    v.push_back(ui->lab45);
    v.push_back(ui->lab46);
    v.push_back(ui->lab47);
    board.push_back(v);

    v.clear();
    v.push_back(ui->lab50);
    v.push_back(ui->lab51);
    v.push_back(ui->lab52);
    v.push_back(ui->lab53);
    v.push_back(ui->lab54);
    v.push_back(ui->lab55);
    v.push_back(ui->lab56);
    v.push_back(ui->lab57);
    board.push_back(v);

    v.clear();
    v.push_back(ui->lab60);
    v.push_back(ui->lab61);
    v.push_back(ui->lab62);
    v.push_back(ui->lab63);
    v.push_back(ui->lab64);
    v.push_back(ui->lab65);
    v.push_back(ui->lab66);
    v.push_back(ui->lab67);
    board.push_back(v);

    v.clear();
    v.push_back(ui->lab70);
    v.push_back(ui->lab71);
    v.push_back(ui->lab72);
    v.push_back(ui->lab73);
    v.push_back(ui->lab74);
    v.push_back(ui->lab75);
    v.push_back(ui->lab76);
    v.push_back(ui->lab77);
    board.push_back(v);
}

void GameWindow::giveHand()
{
    game_.giveHand();
}

void GameWindow::isWin(){
    if(game_.getCurrentPlayerColor()==PlayerColor::RED){
         QMessageBox::information(this,tr("YOU WIN"), tr("<FONT COLOR='#ffffff'>Winner is the RED player</FONT>"));
    }else{
        QMessageBox::information(this,tr("YOU WIN"), tr("<FONT COLOR='#ffffff'>Winner is the BLUE player</FONT>"));
    }
}

void GameWindow::update(){
    if(game_.isWin()){
        isWin();
    }else{
    lblCurrentPlayer();
    lblLeftMoves();
    lblLeftThrows();
    }
}

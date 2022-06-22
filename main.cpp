#include <iostream>
#include "piece.h"
#include "player.h"
#include "controller.h"
#include "game.h"
#include "mainwindow.h"
#include <QApplication>
using namespace std;

int startGraphic(int argc, char *argv[]){
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

int main(int argc, char *argv[])
{

    /*Game game=Game();
    Controller control=Controller(game);
    control.startGame();*/
    startGraphic(argc,argv);
}

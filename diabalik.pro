QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = diabalik.pro
TEMPLATE = app
DEFINES += QT_DEPRECATED_WARNINGS
CONFIG += console # c++11
CONFIG -= app_bundle


QMAKE_CXXFLAGS +=   -pedantic-errors\
                    -std=c++17
SOURCES += \
        board.cpp \
        clickablelabel.cpp \
        controller.cpp \
        game.cpp \
        gamefacade.cpp \
        gamewindow.cpp \
        main.cpp \
        mainwindow.cpp \
        move.cpp \
        piece.cpp \
        player.cpp \
        position.cpp

HEADERS += \
    Observable.h \
    Observer.h \
    board.h \
    clickablelabel.h \
    controller.h \
    direction.h \
    game.h \
    gamefacade.h \
    gamewindow.h \
    mainwindow.h \
    move.h \
    piece.h \
    player.h \
    playercolor.h \
    position.h

FORMS += \
    gamewindow.ui \
    mainwindow.ui

RESOURCES += \
    ressources.qrc

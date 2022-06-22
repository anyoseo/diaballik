#include "gamefacade.h"

GameFacade::GameFacade(bool mode):
    game{Game()}
{
    if(mode)
    game.initializeVariante();
    else
        game.initialize();
}

void GameFacade::move(Position position){
    if(moves.empty())
        throw "The moves vector can't be empty";
    for(int i=0; i<moves.size(); i++){
        if((moves[i].getEnd().getRow()==position.getRow())&&(moves[i].getEnd().getColumn()==position.getColumn())){
            game.movePiece(moves.at(i));
        }
    }
    moves.clear();
    throws.clear();
    notify();
}

void GameFacade::throwBall(Position position){
    if(throws.empty())
        throw "The throws vector can't be empty";
    for(int i=0; i<throws.size(); i++){
        if((throws[i].getRow()==position.getRow())&&(throws[i].getColumn()==position.getColumn())){
            game.throwBall(throws.at(i));
        }
    }
    moves.clear();
    throws.clear();
    notify();
}

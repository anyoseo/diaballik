#ifndef GAMEFACADE_H
#define GAMEFACADE_H
#include "game.h"
#include "board.h"
#include "player.h"
#include "move.h"
#include "playercolor.h"
#include "Observable.h"
#include <iostream>


class GameFacade : public Observable
{
    Game game;
    std::vector<Move> moves;
    std::vector<Position> throws;
    bool asWinner =false;
public:
    /**
     * @brief GameFacade Constructor of the class GameFacade.
     */
    GameFacade(bool);

    /**
     * @brief move Method which moves the piece.
     */
    void move(Position);

    /**
     * @brief throwBall Method which throws the ball.
     */
    void throwBall(Position);

    /**
     * @brief getCurrentPlayerColor Method which gets the color of the current player.
     * @return the color of the curent player.
     */
    inline PlayerColor getCurrentPlayerColor();

    /**
     * @brief leftMoves Method which gets the remaining moves of the player.
     */
    inline unsigned leftMoves();

    /**
     * @brief hasThrow Method which gets if the player has a throw.
     * @return true if he has one else false.
     */
    inline bool hasThrow();

    /**
     * @brief giveHand Method which gives the hand to the opponent.
     */
    inline void giveHand();

    /**
     * @brief newGame Method which intializes a new game.
     */
    inline void newGame();

    /**
     * @brief getBoard Method which returns the board of the game.
     * @return  the board of the game.
     */
    inline std::vector<std::vector<Piece>> getBoard();

    /**
     * @brief setMove Method which sets the moves for a piece.
     * @param position the position of the piece selected.
     */
    inline void setMove(Position position);

    /**
     * @brief getMoves Method which gets the moves for a piece.
     * @return a vector of the possible moves.
     */
    inline std::vector<Move> getMoves();

    /**
     * @brief setThrow Method which sets the throws for a piece.
     */
    inline void setThrow();

    /**
     * @brief getThrowsMethod which gets the throws for a piece.
     * @return a vector of the possible moves  for a throw.
     */
    inline std::vector<Position> getThrows();

    /**
     * @brief isWin Method which checks if the game is over.
     * @return true if it's over else false.
     */
    inline bool isWin();

    /**
     * @brief isFree Method which checks if a square is free.
     * @param position the position of the square.
     * @return true if it is else false.
     */
    inline bool isFree(Position position);
};

PlayerColor GameFacade::getCurrentPlayerColor(){
    return game.getCurrentPlayer().getColor();
}

unsigned GameFacade::leftMoves(){
    return game.getLeftMoves();
}

bool GameFacade::hasThrow(){
    return !game.getHasThrow();
}

void GameFacade::giveHand(){
    this->game.switchPlayer();
    asWinner=game.antiGame();
    notify();
}

void GameFacade::newGame(){
    this->game.initialize();
}

std::vector<std::vector<Piece>> GameFacade::getBoard(){
    return game.getBoard().getBoard();
}

void GameFacade::setMove(Position position){
    if(game.getBoard().getPiece(position).getHasBall()){
        throw "La piece a la balle";
    }

    moves.clear();
    throws.clear();

    moves=game.getMoves(position);
    notify();
}

void GameFacade::setThrow(){
    throws.clear();
    moves.clear();
    throws=game.getThrows();
    notify();
}

bool GameFacade::isFree(Position position){
    return game.getBoard().isFree(position);
}

bool GameFacade::isWin(){
    return asWinner ? true : game.isWin();
}

std::vector<Move> GameFacade::getMoves(){
    return moves;
}

std::vector<Position> GameFacade::getThrows(){
    return throws;
}

#endif // GAMEFACADE_H

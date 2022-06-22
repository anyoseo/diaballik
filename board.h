#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include "position.h"
#include "piece.h"
class Board
{

private:
    std::vector<std::vector<Piece>> board;

public:
    /**
    * @brief Board This is the construcor of the class Board
    * @param height Value of abciss for the board
    * @param width Value of ordinate for the board
    */
    Board();

    /**
     * @brief getBoard This is the getter for the attribute board
     * @return a vector of vector of Square which represents the board
     */
    inline std::vector<std::vector<Piece>>& getBoard();

    /**
     * @brief getSquare This method gets the piece at the given position
     * @param position the position to get the piece from
     * @return a piece of the board
     */
    inline Piece& getPiece(Position position);

    /**
     * @brief put This method puts a piece on the board
     * @param position The position to put the piece
     * @param piece The piece to put on
     */
    inline void put(Piece piece,Position position);

    /**
     * @brief isInside This method checks if a position is inside the board
     * @param position The position to check
     * @return true if it's inside else false
     */
    bool isInside(Position position);

    /**
     * @brief remove This method removes a piece at the given position
     * @param position The position of the piece's to remove at
     */
    inline void remove(Position position);

    /**
     * @brief isMyOwn This method checks if a piece on a board is the same color as the player
     * @param position The position of the piece on the board
     * @param color The color of the player
     * @return true if it's the same else false
     */
    bool isMyOwn(Position position, PlayerColor color);

    /**
     * @brief isFree This method checks if a position on the board is free
     * @param position The position on the board asked
     * @return true if it's free else false
     */
    bool isFree(Position position);

};


std::vector<std::vector<Piece>>& Board::getBoard(){
    return board;
}

Piece& Board::getPiece(Position position){
    return board[position.getRow()][position.getColumn()];
}

void Board::put(Piece piece, Position position){
    board[position.getRow()][position.getColumn()]=piece;
}

void Board::remove(Position position){
    board.at(position.getRow()).at(position.getColumn())=Piece();
}


#endif // BOARD_H

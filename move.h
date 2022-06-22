#ifndef MOVE_H
#define MOVE_H
#include "position.h"
#include "piece.h"

class Move{

    private :

        Position start;
        Position end;
        Piece piece;

   public :

        /**
         * @brief Move This is the constructor of the class Move
         * @param start The initial position of a piece
         * @param end The arrival position of a piece
         * @param piece The piece to move
         */
        Move(Position start,Position end,Piece& piece);

        /**
         * @brief getStart This is the getter for the attribute start
         * @return a reference to the attribute start
         */
        inline Position& getStart();

        /**
         * @brief getEnd This is the getter for the attribute end
         * @return a reference to the attribute position
         */
        inline Position& getEnd();

        /**
         * @brief getPiece This is the getter for the attribute piece
         * @return a reference to the attribute piece
         */
        inline Piece& getPiece();
};

Position& Move::getStart(){
    return this->start;
}

Position& Move::getEnd(){
    return this->end;
}

Piece& Move::getPiece(){
    return this->piece;
}

#endif // MOVE_H

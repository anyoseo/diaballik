#ifndef PIECE_H
#define PIECE_H
#include "playercolor.h"

class Piece
{
private :
    PlayerColor color;
    bool hasBall;
public:

    /**
     * @brief Piece This is the default constructor of the class Piece
     *
     */
    Piece();

    /**
     * @brief Piece This is the constructor with parametersof the class Piece
     * @param color The color of the Player who owns the piece
     */
    Piece(PlayerColor color,bool hasBall);

    /**
     * @brief getColor This is the getter for the attribute color
     * @return The attribute color
     */
    inline PlayerColor getColor();

    /**
     * @brief getHasBall This is the getter for the attribute hasBall
     * @return The attribute hasBall
     */
    inline bool getHasBall();

    /**
     * @brief removeBall This method removes a ball from a piece
     */
    inline void removeBall();

    /**
     * @brief giveBall This method gives the ball to a piece
     */
    inline void giveBall();
};

PlayerColor Piece::getColor(){
    return color;
}
bool Piece::getHasBall(){
    return hasBall;
}

inline void Piece::removeBall(){
    this->hasBall=false;
}

inline void Piece::giveBall(){
    this->hasBall=true;
}

#endif // PIECE_H

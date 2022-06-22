#ifndef POSITION_H
#define POSITION_H
#include "direction.h"
class Position
{

private:
    unsigned row;
    unsigned column;

 public:

    /**
     * @brief Position This is the constructor of the class Position
     * @param row The abciss on the board
     * @param column The ordinate on the board
     */
    Position(unsigned row,unsigned column);

    /**
     * @brief getRow This is the getter of the attribute row
     */
    inline unsigned getRow();

    /**
     * @brief getColumn This is the getter of the attribute column
     */
    inline unsigned getColumn();

    /**
     * @brief next This method gets the position at the direction given from an initial position
     * @return The position next to the initial position
     */
    Position next(Direction direction);

};

unsigned Position::getRow(){
    return row;
}

unsigned Position::getColumn(){
    return column;
}

#endif // POSIITION_H

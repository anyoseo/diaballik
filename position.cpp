#include "position.h"

Position::Position(unsigned row,unsigned column):row{row},column{column}
{

}

Position Position::next(Direction direction){
    switch (direction)
          {
    case Direction::LEFT:
        return (Position(this->row, this->column-1));
    case Direction::RIGHT:
        return (Position(this->row, this->column+1));
    case Direction::UP:
        return (Position(this->row-1, this->column));
    case Direction::DOWN:
        return (Position(this->row+1, this->column));
    case Direction::UP_LEFT:
        return (Position(this->row-1, this->column-1));
     case Direction::DOWN_LEFT:
        return (Position(this->row+1, this->column-1));
     case Direction::UP_RIGHT:
        return (Position(this->row-1, this->column+1));
    case Direction::DOWN_RIGHT:
        return (Position(this->row+1, this->column+1));
          }
    return *this;
}

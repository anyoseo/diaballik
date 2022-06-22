#include "board.h"
Board::Board()
{
    std::vector<Piece> v;
    for (unsigned i = 0 ; i <= 7 ; i++){
        v.clear();
        for (unsigned j = 0 ; j <=7 ; j++){
            v.push_back(Piece());
        }
        board.push_back(v);
    }
}

bool Board::isInside(Position position){
    return position.getRow()<board.size() && position.getColumn()<board.at(0).size();
}

bool Board::isMyOwn(Position position, PlayerColor color){
    return board[position.getRow()][position.getColumn()].getColor()==color;
}

bool Board::isFree(Position position){
    if(board[position.getRow()][position.getColumn()].getColor()==PlayerColor::RED || board[position.getRow()][position.getColumn()].getColor()==PlayerColor::BLUE ){
        return false;
    }else{
        return true;
    }
}

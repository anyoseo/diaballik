#include "player.h"

Player::Player(PlayerColor color): color{color}
{

}

Player& Player::operator=(Player other){
    color=other.color;
    return *this;
}

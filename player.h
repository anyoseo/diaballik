#ifndef PLAYER_H
#define PLAYER_H
#include "playercolor.h"

class Player
{
private:
    PlayerColor color;

public:

    /**
     * @brief Player Constructor of the class Player
     * @param color the player's color
     */
    Player(PlayerColor color);

    /**
     * @brief getColor Getter of the attribute color
     * @return the color of the player
     */
    inline PlayerColor getColor();

    /**
     * @brief operator = Overloading of the affect operator for the switch of player
     * @param other the opponent to switch to
     * @return a player with the same attribute as the other player
     */
    Player& operator=(Player other);
};

PlayerColor Player::getColor(){
    return color;
}

#endif // PLAYER_H

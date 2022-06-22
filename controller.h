#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "game.h"
#include <vector>
#include <string>
#include <iostream>
#include <regex>

class Controller
{

private:
    Game game;
public:
    /**
     * @brief Controller Constructor of the class
     * @param game the value to initialize the attribute game
     */
    Controller(Game& game);

    /**
     * @brief startGame Method which initialize the game
     */
    void startGame();

    /**
     * @brief tokenisation Method which splits the command entered by the user
     * @param tokens the vector which will contains the splited command
     * @param command the command entered by the user
     */
    void tokenisation(std::vector<std::string> &tokens,std::string command);

    /**
     * @brief gestionCommand Method which manages the right action to apply from the user command
     */
    void gestionCommand();

    /**
     * @brief applyMove Method which applies the command move
     * @param index the number which will indiqued the move
     * @param moves the list which will containt moves
     */
    void applyMove(unsigned index, std::vector<Move> moves);

    /**
     * @brief applyMoves Method which applies the command moves
     * @param tokens the vector which will contains the splited command
     * @return a vector which contains the available moves for a piece
     */
    std::vector<Move> applyMoves(std::vector<std::string> &tokens);

    /**
     * @brief applyThrows Method which applies the command throws
     * @return a vector which contains the possible throws
     */
    std::vector<Position> applyThrows();

    /**
     * @brief askCommand Method which ask an input from the user
     * @return the command entered
     */
    std::string askCommand();

    /**
     * @brief askVariante Method which ask an input from the user for the type of game
     * @return the command entered
     */
    std::string askVariante();

    /**
     * @brief displayWelcome Method which displays a welcome message
     */
    void displayWelcome();

    /**
     * @brief displaySwitchEnd Method which displays the switch of player
     * @param color the color of the player's turn
     */
    void displaySwitchEnd(PlayerColor color);

    /**
     * @brief displayBoard Method which displays the game's board
     */
    void displayBoard();

    /**
     * @brief diplayMoves Method which displays the available moves for a piece
     * @param moves the vector of the available moves
     */
    void diplayMoves(std::vector<Move> moves);

    /**
     * @brief displayThrows Method which displays the available throws
     * @param positions the vector of positions for the possible throws
     */
    void displayThrows(std::vector<Position> positions);

    void displayLeftMoves();

    /**
     * @brief displayHelp Method which displays the differents commands available in the game
     */
    void displayHelp();
};


#endif // CONTROLLER_H

#ifndef GAME_H
#define GAME_H
#include "board.h"
#include "player.h"
#include "move.h"
#include "playercolor.h"

class Game
{
private:
    Board board;
    Player current;
    Player opponent;
    Position* selected;
    unsigned leftMoves;
    bool hasThrow;
public:

    /**
     * @brief Game Constuctor of class Game
     *
     */
    Game();

    /**
     * @brief getBoard Gets the attribute board of the class.
     * @return the attribute board of type Board
     */
    inline Board& getBoard();

    /**
     * @brief getCurrentPlayer Gets the attribute current of the class.
     * @return the attribute current of type Player
     */
    inline Player& getCurrentPlayer();

    /**
     * @brief getSelected This is the getter for the attribute selected
     * @return Attribute selected of type Position
     */
    inline Position& getSelected();

    /**
     * @brief getLeftMoves Getter for the attribute leftMoves
     */
    inline unsigned getLeftMoves();

    /**
     * @brief getHasThrow Getter for the attribute hasThrow
     */
    inline bool getHasThrow();

    /**
     * @brief setSelected This is the setter for the attribute selected
     */
    inline void setSelected(Position& position);

    /**
     * @brief isWin Verify is the game is over if there's an antigame or a piece on the opponent side
     * @return true if it's over else false
     */
    inline bool isWin();

    /**
     * @brief initialize This method initialize all the game
     */
    void initialize();

    /**
     * @brief initializeVarainte This method initialize all the game
     */
    void initializeVariante();

    /**
     * @brief movePiece This method move a piece to a new position received
     * @param move The move to apply to a piece to a new position
     */
    void movePiece(Move move);

    /**
     * @brief getGameBoard This method gets the board's game of the class's attribute board
     * @return the board of the game
     */
    inline std::vector<std::vector<Piece>>& getGameBoard();

    /**
     * @brief antiGame This method checks if there's an antigame situation
     * @return  true if there's an antigame sitation else false
     */
    bool antiGame();

    /**
     * @brief getMoves This method gets all the possible moves available for a Piece displacement
     * @param position The position of the piece selected
     * @return A vector of the available moves
     */
     std::vector<Move> getMoves(Position position);

    /**
     * @brief isOppositeSide This method checks if there's a piece of the current player on the last line of the opponent player
     * @return true if there's on else false
     */
    bool isOppositeSide();

    /**
     * @brief getThrows This method gets all the possible position available to throw a ball to
     * @return A vector of the available positions.
     */
    std::vector<Position> getThrows();

    /**
     * @brief getWinner This method gets the winner of the game
     * @return A player which is the winner
     */
    inline Player getWinner();

    /**
     * @brief canMove This method checks if a piece can move only if it has no ball
     * @param position The position of the selected piece
     * @return true if it can move else false
     */
    inline bool canMove(Position position);

    /**
     * @brief endHand This method checks if it's the end hand for the current player
     * @return true if it's over else false
     */
    inline bool endHand();

    /**
     * @brief isThrowable This method checks if a ball can be thrown from a piece selected
     * @param position The selected piece's position
     * @return true if it can be thrown else false
     */
    inline bool isThrowable(Position position);

    /**
     * @brief throwBall This method throws a ball to a new position
     */
    void throwBall(Position);

    /**
     * @brief switchPlayer This method switch the current player and the opponent player
     */
    void switchPlayer();

};


Board& Game::getBoard(){
    return this->board;
}

Player& Game::getCurrentPlayer(){
    return this->current;
}

Position& Game::getSelected(){
    return *this->selected;
}

unsigned Game::getLeftMoves(){
    return leftMoves;
}

bool Game::getHasThrow(){
    return hasThrow;
}

void Game::setSelected(Position& position){
    this->selected=&position;
}

std::vector<std::vector<Piece>>& Game::getGameBoard(){
    return board.getBoard();
}

bool Game::isWin(){
    return isOppositeSide();
}

Player Game::getWinner(){
    return Game::antiGame() ? this->current : this->opponent;
}

bool Game::endHand(){
    return this->leftMoves==0 ? this->hasThrow==false : false;
}

bool Game::canMove(Position position){
    return !board.getPiece(position).getHasBall();
}
bool Game::isThrowable(Position position){
    return board.getPiece(position).getHasBall() && hasThrow;
}

#endif // GAME_H

#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QPainter>
#include <vector>
#include "gamefacade.h"
#include "iostream"
#include "clickablelabel.h"

namespace Ui {
class GameWindow;
}

class GameWindow : public QDialog, public Observer
{
    Q_OBJECT

public:
    /**
     * @brief GameWindow Constructor for the class GameWindow.
     * @param parent the parent of the widget.
     * @param mode the mode selected.
     */
    explicit GameWindow(QWidget *parent = nullptr, bool mode = false);
    ~GameWindow();
    GameFacade game_;

private:
    std::vector<QVector<ClickableLabel*>> board;
    Ui::GameWindow *ui;

    /**
     * @brief update Method for the update of the Observer.
     */
    void update();

    /**
     * @brief lblCurrentPlayer Method which displays the current player.
     */
    void lblCurrentPlayer();

    /**
     * @brief lblLeftMoves Method which displays the remaining moves of the player.
     */
    void lblLeftMoves();

    /**
     * @brief lblLeftThrows Method which displays if the player has a throw.
     */
    void lblLeftThrows();

    /**
     * @brief initializeBoard Method which initializes the board of the game.
     */
    void initializeBoard();

    /**
     * @brief connection Method which connects the giveHandButton to the action and initializes the clickable labels.
     */
    void connection();

    /**
     * @brief setSquare Method which initializes the row and column for each clickable label.
     */
    void setSquare();

    /**
     * @brief giveHand Method which gives the hand to the opponent.
     */
    void giveHand();

    /**
     * @brief loadLabel Method which initializes the board of clickable labels.
     */
    void loadLabel();

    /**
     * @brief isWin Method which displays the winner of the game.
     */
    void isWin();
};


#endif // GAMEWINDOW_H

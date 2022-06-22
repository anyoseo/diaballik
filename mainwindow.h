#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QPainter>

#include <vector>
#include "game.h"
#include "board.h"
#include "piece.h"
#include "gamewindow.h"

namespace Ui {
class MainWindow;

}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:

    /**
     * @brief MainWindow Constructor of the class MainWindow.
     * @param parent the parent widget.
     */
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:
    /**
     * @brief on_pushButton_clicked Method which launches the game when the button is pushed.
     */
    void on_pushButton_clicked();

private:

    Ui::MainWindow *ui;
    GameWindow *gameWindow;
};

#endif // MAINWINDOW_H

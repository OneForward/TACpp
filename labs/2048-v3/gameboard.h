#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QLabel>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QKeyEvent>
#include "game.h"
#include "cell.h"
class GameBoard : public QWidget
{
    Q_OBJECT
public:
    explicit GameBoard(QWidget *parent = 0);

private:
    // main game logic
    Game game;

    Cell* cells[NCells][NCells] {};

    // main layout
    QVBoxLayout *mainLayout;

    // grid layout of board
    QGridLayout *boardLayout;

    // score widget
    QLabel *score;

    void drawBoard();
protected:
    void keyPressEvent(QKeyEvent *event);
};

#endif // GAMEBOARD_H

#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QLabel>
#include <QVBoxLayout>
#include <QGridLayout>

class GameBoard : public QWidget
{
    Q_OBJECT
public:
    explicit GameBoard(QWidget *parent = 0);

private:

    // main layout
    QVBoxLayout *mainLayout;
    // grid layout of board
    QGridLayout *boardLayout;
    // score widget
    QLabel *score;

};

#endif // GAMEBOARD_H

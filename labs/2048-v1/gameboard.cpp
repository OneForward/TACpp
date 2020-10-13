#include "gameboard.h"

GameBoard::GameBoard(QWidget *parent) :
    QWidget(parent)
{
    // set default size
    resize(650,450);

    // create the main layout
    mainLayout = new QVBoxLayout();
    setLayout(mainLayout);

    // create the board layout
    boardLayout = new QGridLayout();
    // auto cell = new QLabel();
    // cell->setText("2");
    // cell->setAlignment(Qt::AlignCenter);
    // cell->setStyleSheet("QLabel { background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; }");
    // boardLayout->addWidget(cell);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            auto cell = new QLabel();
            cell->setText("2");
            cell->setAlignment(Qt::AlignCenter);
            cell->setStyleSheet("QLabel { background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; }");
            boardLayout->addWidget(cell, i, j);
        }
    }
    mainLayout->insertLayout(0, boardLayout);

    // create the score widget and add it to the board
    score = new QLabel(QString("SCORE: %1").arg(0));
    score->setStyleSheet("QLabel { color: rgb(235,224,214); font: 16pt; }");
    score->setFixedHeight(50);
    mainLayout->insertWidget(1, score, 0, Qt::AlignRight);

    // style sheet of the board
    setStyleSheet("GameBoard { background-color: rgb(187,173,160) }");
}





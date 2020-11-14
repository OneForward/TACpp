#include "gameboard.h"
#include "cell.h"
#include <cstdlib>

GameBoard::GameBoard(QWidget *parent) :
    QWidget(parent)
{
    // set default size
    resize(650, 450);

    // create the main layout
    mainLayout = new QVBoxLayout();
    setLayout(mainLayout);

    // create the board layout
    boardLayout = new QGridLayout();

    drawBoard();

    mainLayout->insertLayout(0, boardLayout);

    // create the score widget and add it to the board
    score = new QLabel(QString("SCORE: %1").arg(0));
    score->setStyleSheet("QLabel { color: rgb(235,224,214); font: 16pt; }");
    score->setFixedHeight(50);
    mainLayout->insertWidget(1, score, 0, Qt::AlignRight);

    // style sheet of the board
    setStyleSheet("GameBoard { background-color: rgb(187,173,160) }");
}


void GameBoard::drawBoard()
{
    delete boardLayout;
    boardLayout = new QGridLayout();
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            auto cell = new Cell(rand()%2 ? 0 : 1<<(rand()%8 + 1));
            cell->draw();
            boardLayout->addWidget(cell, i, j); // 将这个 Cell 插入到 boardLayout 的 第 i 行 第 j 列
        }
    }
    mainLayout->insertLayout(0, boardLayout); // 将 boardLayout 插入到 mainLayout 里面
}


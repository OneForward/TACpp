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
    for (int i = 0; i < NCells; ++i) {
        for (int j = 0; j < NCells; ++j) {
            delete cells[i][j];
            cells[i][j] = new Cell(game.board[i][j]);
            boardLayout->addWidget(cells[i][j], i, j);
            cells[i][j]->draw();
        }
    }
    mainLayout->insertLayout(0, boardLayout);
}

void GameBoard::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Up:
        game.move(false, false);
        break;
    case Qt::Key_Down:
        game.move(false, true);
        break;
    case Qt::Key_Left:
        game.move(true, false);
        break;
    case Qt::Key_Right:
        game.move(true, true);
        break;
    }

    if (game.changed) {
        if (!game.isfull()) {
            auto pos = game.getEmptyPos();
            game.board[pos[0]][pos[1]] = 2;
        }
        score->setText(QString("SCORE: %1").arg(game.total_score));
        drawBoard();
    }
}

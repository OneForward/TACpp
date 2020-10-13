#include <QApplication>
#include "gameboard.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    GameBoard board;
    board.show();

    return app.exec();
}

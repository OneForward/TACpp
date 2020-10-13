#include <QApplication>
#include "gameboard.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    srand(time(0));
    GameBoard board;
    board.show();

    return app.exec();
}

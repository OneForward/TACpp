#ifndef GAME_H
#define GAME_H

#include <array>

const int NCells = 4;

using Pos = std::array<int, 2>;

class Game
{
public:

    int board[NCells][NCells];

    int total_score = 0;
    bool changed;

    Game();

    void move(bool horizonal, bool reverse);

    void resetGame();

    Pos getEmptyPos();

    bool isfull();
//    bool wonGame();
};

#endif // GAME_H

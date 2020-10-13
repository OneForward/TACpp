#include <algorithm>
#include <cstring>
#include <vector>
#include "game.h"

Game::Game()
{
    resetGame();
}

void Game::resetGame()
{
    memset(board, 0, sizeof board);

    board[rand()%NCells][rand()%NCells] = 2;

    auto pos = getEmptyPos();
    board[pos[0]][pos[1]] = 2;

    total_score = 0; changed = true;
}

Pos Game::getEmptyPos()
{
    int i,j;
    do {
        i = rand() % NCells;
        j = rand() % NCells;
    } while (board[i][j]);
    return {i, j};
}


bool Game::isfull()
{
    return std::all_of(*board, *board + NCells * NCells, [](int x) { return x != 0; } );
}


void Game::move(bool horizonal, bool reverse)
{
    static int board_prev[NCells][NCells];
    memcpy(board_prev, board, sizeof board); //backup

    using Vec = std::vector<int> ;
    auto squeezeVec = [&] (Vec v, bool reverse) -> Vec {
        if (reverse) v = Vec(v.rbegin(), v.rend());
        Vec ans; size_t first = 0;
        while (first+1 < v.size()) {
            if (v[first] == v[first+1]) {
                total_score += v[first] * 2;
                ans.push_back(v[first] * 2), first += 2;
            }
            else ans.push_back(v[first]), first++;
        }
        if (first+1 == v.size()) ans.push_back(v[first]);
        while (ans.size() < NCells) ans.push_back(0);
        return reverse ? Vec(ans.rbegin(), ans.rend()) : ans;
    };

    auto getVal = [&] (size_t i, size_t j) -> int& {
        return horizonal ? board[i][j] : board[j][i];
    };

    for (size_t i=0; i < NCells; ++i) {
        Vec v;
        for (size_t j=0; j < NCells; ++j) {
            if (getVal(i, j)) v.push_back(getVal(i, j));
        }
        auto ans = squeezeVec(v, reverse);
        for (size_t j=0; j < NCells; ++j) {
            getVal(i, j) = ans[j];
        }
    }
    changed = !std::equal(*board, *board + NCells * NCells, *board_prev );
}


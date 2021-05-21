/*
    迷宫
    bfs
*/

#include <iostream>
#include <queue>
using namespace std;

struct Pos
{
    int x, y;
};


int main()
{
    // freopen("in.txt", "r", stdin);
    
    const int MAX = 105;
    const int DIR[][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    int N, M, x1, y1, x2, y2, ans = -1;
    char Maze[MAX][MAX];
    bool visited[MAX][MAX];

    cin >> N >> M >> x1 >> y1 >> x2 >> y2;
    
    // 初始化
    for (int i = 1; i <= N; ++i) 
        for (int j = 1; j <= M; j++)
            cin >> Maze[i][j];
    
    // BFS
    queue<Pos> Q;
    Q.push({x1, y1}); visited[x1][y1] = true;
    while (Q.size()) {
        int len = Q.size(); ans++;
        while (len--) {
            auto [x, y] = Q.front(); Q.pop();
            if (x == x2 and y == y2) { cout << ans; return 0; }
            for (auto&& [dx, dy]: DIR) {
                auto r = x + dx, c = y + dy;
                if (r <= 0 or r > N or c <= 0 or c > M or visited[r][c] or Maze[r][c] == '*') continue;
                if (dx == 0 and (Maze[x][y] == '|' or Maze[r][c] == '|')) continue; // 竖直
                if (dy == 0 and (Maze[x][y] == '-' or Maze[r][c] == '-')) continue; // 水平
                visited[r][c] = true; 
                Q.push({r, c});
            }
        }
    }
    cout << -1;

    return 0;
}

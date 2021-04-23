#include <iostream>
#include <cstring>
using namespace std;

const int SIZE = 20;

struct Logo
{
    // 0, 1, 2, 3: ↑ ← ↓ →
    enum DIRECTION {UP, LEFT, DOWN, RIGHT} direction;

    bool canvas[SIZE][SIZE] = {};
    int x = 0, y = 0;

    void setDirection(int op) {
        if (op == 1) direction = UP;
        if (op == 2) direction = DOWN;
        if (op == 3) direction = (DIRECTION)((direction + 1) % 4 );
        if (op == 4) direction = (DIRECTION)((direction + 3) % 4 );
    }

    void move() {
        int steps; cin >> steps;
        while (steps--) { 
            if (direction == UP   ) canvas[--x][y] = true;
            if (direction == DOWN ) canvas[++x][y] = true;
            if (direction == LEFT ) canvas[x][--y] = true;
            if (direction == RIGHT) canvas[x][++y] = true;
        }        
    }

    void printCanvas() {
        for (int i = 0; i < SIZE; ++i) { 
            for (int j = 0; j < SIZE; ++j) { 
                cout << ((canvas[i][j]) ? '*' : ' ');
            }
            cout << endl;
        }
    }

};

void showOption(){
    cout<<"欢迎来到Logo绘制系统："<<endl;
    cout<<"1--笔向上"<<endl;
    cout<<"2--笔向下"<<endl;
    cout<<"3--左转"<<endl;
    cout<<"4--右转"<<endl;
    cout<<"5 n--前进n格（n为正整数）"<<endl;
    cout<<"6--打印20*20数组"<<endl;
    cout<<"9--数据结束（标记）"<<endl;
}

int main()
{

    showOption();

    Logo logo;  int op;

    while (true) {
        cin >> op;
        if (op <= 4) logo.setDirection(op);
        else if (op == 5) logo.move();
        else if (op == 6) logo.printCanvas();
        else break;
    }
}

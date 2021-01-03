#include <iostream>
using namespace std;


// cin.sync() 行为不确定
// gcc 中 cin.sync() 清空输入缓冲区的所有内容
// msvc 中 cin.sync() 什么也没做
void test2() {
    freopen("cases/test2.txt", "r", stdin);
    int x, y;
    cin >> x;  cout << "x = " << x << endl; 
    cin.sync();
    cin >> y;  cout << "y = " << y << endl;
}


// cin.ignore(size_t, char) 通常与 cin.clear() 结合使用
// 保证不同的编译器效果一致
// cin.clear() : 将输入状态置位
// cin.ignore(size_t n, char delim): 废弃输入流，直到遇到分隔符 delim，或者达到 n 个字符
void test3() {
    freopen("cases/test3.txt", "r", stdin);
    int x, y;
    cin >> x; cout << x << endl;
    cin.clear(); 
    cin.ignore(100000, '\n');
    cin >> y; cout << y << endl;
}


int main() {
    test2();
    // test3();
}



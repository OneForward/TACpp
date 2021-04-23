#include <iostream>
using namespace std;
//此处填补2行代码
string myfun(int& a, int& b, string s="  ");
int myfun(int* a, int* b);
int main() {
    int x, y;
    cin >> x >> y;
    cout << myfun(x, y);
    cout << x << ' ' << y;
    return 0;
}
int myfun(int* a, int* b) {
    int c = *a - *b;
    *a *= 2;
    *b *= 3;
    return c;
}
//此处定义一个函数
string myfun(int& a, int& b, string s) {
    s[0] = abs(myfun(&b, &a)) % 10 + '0';
    return s;
}
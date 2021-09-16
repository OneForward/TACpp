#include<iostream>
using namespace std;

int main() 
{
    int x;
    cin >> x;

    int a = x / 100, b = x / 10 % 10, c = x % 10;
    int tmp;

    if (a < b) tmp = a, a = b, b = tmp;
    if (a < c) tmp = a, a = c, c = tmp;
    if (b < c) tmp = b, b = c, c = tmp;

    int y = a * 100 + b * 10 + c;
    cout << y;
    return 0;
}


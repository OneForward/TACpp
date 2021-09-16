#include<iostream>
using namespace std;

int main() 
{
    int x; cin >> x;
    int x_tmp = x, y = 0;

    while (x) {
        y = y * 10 + x % 10;
        x /= 10;
    }

    cout << (x_tmp == y ? "Yes" : "No");
    return 0;
}
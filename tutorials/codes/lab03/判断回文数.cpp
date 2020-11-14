#include<iostream>
using namespace std;

int main() 
{
    int x; cin >> x;

    int x2 = x, y = 0;
    while (x) {
        y = y * 10 + x % 10;
        x /= 10;
    }
    if (y == x2) cout << "Yes";
    else cout << "No";
    return 0;
}


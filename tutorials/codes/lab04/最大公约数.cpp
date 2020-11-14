#include <iostream>

using namespace std;

int gcd(int x, int y) {
    while (x && y) {
        x %= y;
        swap(x, y);
    }
    return x;
}

int main()
{

    int n, m; 
    // n = 90, m = 120;
    cin >> n >> m;
    
    cout << gcd(n, m);

    return 0;
}

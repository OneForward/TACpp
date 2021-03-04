#include<iostream>

using namespace std;

int main() 
{

    int n, m, a, b, c, d;
    cin >> n >> m;
    
    a = (n % 10 + 7) % 10; n /= 10; 
    b = (n % 10 + 7) % 10; n /= 10;
    c = (n % 10 + 7) % 10; n /= 10;
    d = (n % 10 + 7) % 10; n /= 10;
    // d c b a -> b a d c
    if (b) cout << b;
    cout << a << d << c << " ";

    a = (m % 10 + 3) % 10; m /= 10; 
    b = (m % 10 + 3) % 10; m /= 10;
    c = (m % 10 + 3) % 10; m /= 10;
    d = (m % 10 + 3) % 10; m /= 10;
    // d c b a -> b a d c
    if (b) cout << b;
    cout << a << d << c << " ";

    return 0;
}


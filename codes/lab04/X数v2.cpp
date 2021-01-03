#include <iostream>

using namespace std;

inline int cubic(int x) { return x * x * x; };

bool is_x_number(int x)
{
    int ans = 0, x_copy = x;
    while (x)
    {
        ans += cubic(x % 10);
        x /= 10;
    }
    return ans == x_copy;
}

int main()
{
    bool found = false;
    int a, b; 
    cin >> a >> b;
    
    for (int x = a; x <= b; ++x) { 
        if (x > 1000) break;
        if (is_x_number(x)) cout << x << " ", found = true;
    }
    if (!found) cout << "no";


    return 0;
}

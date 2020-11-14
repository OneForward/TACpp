#include <iostream>

using namespace std;

int rev(int x) {
    int ans = 0;
    while (x) ans = ans * 10 + x % 10, x /= 10;
    return ans;
}

int main()
{

    int n; cin >> n;

    int cnt = 0;

    for (int x = 0; x < n; ++x) { 
        if (x + rev(x) == n) cnt++;
    }
    
    cout << cnt;
    return 0;
}

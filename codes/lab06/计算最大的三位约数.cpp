#include <iostream>

using namespace std;

int f(int n) {
    for (int i = 999; i >= 100; --i) { 
        if (n % i == 0) return i;
    }
    return -1;
}

int main()
{
    int n; cin >> n;
    if (n < 1000 || n > 1000000) cout << "Input error!";
    else {
        int ans = f(n);
        if (ans == -1) cout << "Not found!";
        else cout << ans;
    }
}

#include <iostream>

using namespace std;

int main()
{
    long long fib[81] = {0, 1};

    int n; cin >> n;

    for (int i = 2; i <= n; ++i) { 
        fib[i] = fib[i-1] + fib[i-2];
    }
    cout << fib[n] << endl;

    return 0;
}

#include <iostream>
using namespace std;

const int N = 15;

int main() {
    int n; cin >> n;
    int f[N][N]{}, x;
    
    for (int i = 0; i < n; ++i) { 
        cin >> x;
        f[i][0] = f[i-1][0] + x;
        for (int j = 1; j <= i; ++j) { 
            cin >> x;
            f[i][j] = max(f[i-1][j-1], f[i-1][j]) + x;
        }
    }

    int maxVal = 0;
    for (int i = 0; i < n; ++i) { 
        maxVal = max(maxVal, f[n-1][i]);
    }
    cout << maxVal;


    return 0;
}


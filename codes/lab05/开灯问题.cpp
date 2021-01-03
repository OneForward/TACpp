#include <iostream>

using namespace std;

int main()
{
    int n, K;
    cin >> n >> K;

    bool A[1005]{}; 
    for (int k = 1; k <= K; ++k) { 
        for (int i = 0; i <= n; i += k) { 
            A[i] = !A[i];
        }
    }

    for (int i = 1; i <= n; ++i) { 
        if (A[i]) cout << i << " ";
    }

    return 0;
}

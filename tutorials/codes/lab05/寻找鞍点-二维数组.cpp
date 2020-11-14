#include <iostream>
#include <limits.h>
using namespace std;

const int N = 10;

int main(int argc, char const *argv[])
{
    int m, n, A[N][N];
    cin >> m >> n;
    for (int i = 0; i < m; ++i) { 
        for (int j = 0; j < n; ++j) { 
            cin >> A[i][j];
        }
    }

    int rowMax[N], colMin[N];
    for (int i = 0; i < m; ++i) { 
        int maxVal = INT_MIN;
        for (int j = 0; j < n; ++j) { 
            maxVal = max(maxVal, A[i][j]);
        }
        rowMax[i] = maxVal;
    }

    for (int j = 0; j < n; ++j) { 
        int minVal = INT_MAX;
        for (int i = 0; i < m; ++i) { 
            minVal = min(minVal, A[i][j]);
        }
        colMin[j] = minVal;
    }

    bool found = false;
    for (int i = 0; i < m; ++i) { 
        for (int j = 0; j < n; ++j) {
            if (A[i][j] == rowMax[i] && A[i][j] == colMin[j]) {
                found = true;
                printf("mat[%d][%d]=%d\n", i, j, A[i][j]); 
            }
        }
    }

    if (!found) printf("Not Found\n");

    return 0;
}

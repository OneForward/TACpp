#include <iostream>
#include <limits.h>
using namespace std;

const int MAX_SIZE = 10;

int main()
{
    int m, n, A[MAX_SIZE][MAX_SIZE];
    int rowMax[MAX_SIZE], colMin[MAX_SIZE];

    for (int i = 0; i < MAX_SIZE; ++i) rowMax[i] = INT_MIN, colMin[i] = INT_MAX;
    cin >> m >> n;

    for (int i = 0; i < m; ++i) { 
        for (int j = 0; j < n; ++j) { 
            cin >> A[i][j];
            rowMax[i] = max(rowMax[i], A[i][j]);
            colMin[j] = min(colMin[j], A[i][j]);
        }
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

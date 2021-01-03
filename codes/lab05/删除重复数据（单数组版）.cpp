#include <iostream>
using namespace std;

int main()
{
    int A[10005], x;

    int n = 0;
    while (cin >> x) {
        bool found = false;
        for (int i = 0; i < n; ++i) { 
            if (A[i] == x) { found = true; break; }
        }
        if (!found) A[n++] = x;
    }
    for (int i = 0; i < n; ++i) { 
        cout << A[i] << " ";
    }
    return 0;
}

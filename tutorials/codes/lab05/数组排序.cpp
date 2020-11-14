#include <iostream>

using namespace std;

void bubbleSort(int* A, int n) {    
    for (int i=n-1; i>=0; --i) {
        bool exist_swap = false;
        for (int j=0; j<i; ++j) {
            if (A[j] < A[j+1]) swap(A[j], A[j+1]), exist_swap = true;
        }
        if (! exist_swap) break;
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    int* A = new int[n];

    for (int i = 0; i < n; ++i) { 
        cin >> A[i];
    }

    bubbleSort(A, n);

    for (int i = 0; i < n; ++i) { 
        cout << A[i] << " ";
    }

    return 0;
}

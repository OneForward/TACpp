#include <iostream>
using namespace std;

template<class T>
T findKmax( T*  A, int n, int k) {
    // 选择排序; 平均, 最坏: O(NK)
    for (int i = 0; i < k; i++) {
        for(int j = i + 1; j < n; j++){
            if (A[j] > A[i])  swap(A[j], A[i]);
        }
    }
    return A[k - 1];
}

template<class T>
int partition(T* A, int lft, int rht) {
    // A[..i) < x <= A[i..j]
    T x = A[rht], i = lft;
    for (int j = lft; j < rht; ++j) {
        if (A[j] >= x) {
            swap(A[i], A[j]);
            i++;
        }
    }
    swap(A[i], A[rht]);
    return i;
}

template<class T>
T findKmax(T* A, int lft, int rht, int k) {
    // 分治; 平均意义 O(N), 最坏 O(N^2)
    auto mid = partition(A, lft, rht);
    if (mid - lft == k-1) return A[mid];
    if (mid - lft >= k) return findKmax(A, lft, mid-1, k);
    return findKmax(A, mid+1, rht, k - mid + lft - 1);
}



int main() 
{
    int n, k;
    cin >> n >> k;
    long long * A = new long long [n]; // force allocated on heap

    for (int i = 0; i < n; i++) cin >> A[i];

    // cout << findKmax<long long>(A, n, k) << endl;
    cout << findKmax<long long>(A, 0, n-1, k) << endl;

    delete[] A;
    return 0;    
} 
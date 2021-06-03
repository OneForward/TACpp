#include <iostream>
#include <iomanip>
#include <algorithm>
#include <functional>
// #include "LeetCpp.utils.hpp"
using namespace std;
int N = 6;

void countingSort1(vector<int>& A, int K) {
    // A 中的数字都在 [0, K) 中
    // out-of-place, stable, 但是当前版本的实现不是 stable
    // Time: O(N+K), Space: O(K)
    vector<int> C(K);
    for (const auto& x: A) C[x]++;

    int i = 0;
    for (int x = 0; x < K; x++) {
        while (C[x]) {
            A[i++] = x;
            C[x]--;
        }
    }
}
void countingSort(vector<int>& A, int K) {
    // A 中的数字都在 [0, K) 中
    // out-of-place, stable, 
    // Time: O(N+K), Space: O(N+K)
    int N = A.size();
    vector<int> C(K), B(N);
    for (const auto& x: A) C[x]++;

    for (size_t i = 1; i < K; i++) C[i] += C[i-1];
    
    for (auto px = A.rbegin(); px != A.rend(); ++px) {
        auto x = *px;
        B[--C[x]] = x; ;
    }
    A = B;
}

void insertSort(int A[], int lft, int rht) {
    // 对几乎排好序的数组只需要 O(N) 的时间
    for (int i = lft+1; i <= rht; ++i) { 
        auto x = A[i];
        
        int j;
        for (j = i-1; j >= lft and A[j] > x; --j) {
            A[j+1] = A[j];
        }
        A[j+1] = x;
    }
}

template <class BidIt>
void insertSort(BidIt first, BidIt last) {
    // 对几乎排好序的数组只需要 O(N) 的时间
    for (auto rht=next(first); rht != last; ++rht) {
        auto x = *rht;
        auto lft = prev(rht);
        for (; lft >= first and x < *lft; --lft) *next(lft) = *lft;
        *next(lft) = x; 
    }
}



template<class T>
void merge(T* A, T* B, int L1, int R1, int L2, int R2) {
    // 实际上 R1 == L2 是连续的
    auto p1 = L1, p2 = L2, i = L1;
    while (p1 < R1 and p2 < R2) {
        if (A[p1] < A[p2]) B[i++] = A[p1++];
        else B[i++] = A[p2++];
    }
    while (p1 < R1) B[i++] = A[p1++];
    while (p2 < R2) B[i++] = A[p2++];
    
    i = L1;
    while (i < R2) A[i] = B[i], i++;
}

template<class T>
void merge_sort(T* A, int n) {
    T* B = new int[n];
    for (int k = 1; k < n; k *= 2)
    {
        for (int i = 0; i < n; i += 2 * k)
        {
            merge(A, B, i, i+k, i+k, min(i+2*k, n));
        }
    }
}


template <class T>
void merge_sort_recursive(T* A, T* B, int lft, int rht) {
    if (rht - lft <= 1) return;
    int mid = (lft + rht + 1) / 2;
    merge_sort_recursive(A, B, lft, mid);
    merge_sort_recursive(A, B, mid, rht);

    merge(A, B, lft, mid, mid, rht);
}

template <class T>
void merge_sort_v1(T* A, int len) {
    T* B = new T[len];
    merge_sort_recursive(A, B, 0, len);
}


template <class T, class Comp=less<T>>
void bubbleSort(T* A, int lft, int rht) {
    bool exist_swap;
    for (int i = rht; i > lft; --i) {
        exist_swap = false;
        for (int j = lft; j < i; ++j) {
            if (Comp()(A[j+1], A[j])) swap(A[j], A[j+1]), exist_swap = true;
        }
        if (not exist_swap) break;
    }
}

template <class T, class Comp=less<T>>
void bubbleSort2(T* A, int N) {
    for (int i = 0; i < N-1; ++i) {
        auto exist_swap = false;
        for (int j = 0; j < N-i-1; ++j) {
            if (Comp()(A[j+1], A[j])) swap(A[j], A[j+1]), exist_swap = true;
        }
        if (not exist_swap) break;
    }
}

template <class T, class Comp=less<T>>
int partition1(T* A, int lft, int rht) {
    int pivot = rand() % (rht - lft + 1) + lft;
    swap(A[pivot], A[lft]);

    T pivotVal = A[lft];

    while (lft != rht) {
        while (lft < rht && A[rht] >= pivotVal) --rht;
        if (lft < rht) A[lft] = A[rht], ++lft;
        while (lft < rht && A[lft] <= pivotVal)  ++lft;
        if (lft < rht) A[rht] = A[lft], --rht;
    }
    A[lft] = pivotVal;

    return lft;
}
template <class T, class Comp=less<T>>
void qsort(T* A, int lft, int rht) {
    if (lft >= rht) return;
    int pivot = partition1(A, lft, rht);
    qsort(A, lft, pivot);
    qsort(A, pivot+1, rht);
}

template <class T, class Comp=less<T>>
int partition2(T* A, int lft, int rht) {
    int pivot = rand() % (rht - lft + 1) + lft;
    T pivotVal = A[pivot];
    swap(A[pivot], A[rht]);

    int storeIndex = lft;
    for (int i = lft; i < rht; ++i)
        if (Comp()(A[i], pivotVal)){
            if (i != storeIndex)
                swap(A[storeIndex], A[i]);
            storeIndex++;
        }
    swap(A[rht], A[storeIndex]);

    return storeIndex;
}

template <class T, class Comp=less<T>>
int partition(T* A, int lft, int rht) {
    int pivot = rand() % (rht - lft + 1) + lft;
    T pivotVal = A[pivot];
    swap(A[pivot], A[rht]);

    // we make sure [low, i) <= x < [i, j]
    int i = lft;
    for (int j = lft; j < rht; ++j) {
        if (A[j] <= pivotVal) {
            swap(A[i], A[j]); ++i;
        }
    }
    swap(A[i], A[rht]);
    return i;
}

template <class T, class Comp=less<T>>
int partitionv2(T* A, int L, int R) {
    int pivot = rand() % (R - L + 1) + L;
    T x = A[pivot];
    swap(A[pivot], A[R]);

    // we make sure [low, i) <= x < [i, j]
    int lft = L;
    for (int rht = L; rht < R; ++rht) {
        if (A[rht] < x) swap(A[lft++], A[rht]);
    }
    swap(A[lft], A[R]);
    return lft;
}

template <class T, class Comp=less<T>>
void qsort2(T* A, int lft, int rht) {
    if (lft >= rht) return;
    int pivot = partition2<T, Comp>(A, lft, rht);
    qsort2<T, Comp>(A, lft, pivot-1);
    qsort2<T, Comp>(A, pivot+1, rht);
}

template<class T> 
void printArray(T* A, int len) {
    cout << "{ ";
    for (size_t i = 0; i < len; i++)
    {
        cout << A[i] << ", ";
    }
    cout << " }\n";
}

int main(int argc, char const *argv[])
{
    // vector<int> v = {1, 3, 7, 8, 2, 3, 5};
    // insertSort(v.begin(), v.end());
    // cout << v << endl;


    // int* A = new int[N];
    int A[] = {1, 3, 7, 8, 2, 3, 5}; int N = sizeof A / sizeof A[0];
    // for (int i=0; i<N; ++i) A[i] = rand() % (N*N);
    // for (int i=0; i<N; ++i) cout << setw(4) << i; cout << endl;
    // for (int i=0; i<N; ++i) cout << setw(4) << A[i]; cout << endl;
    merge_sort<int>(A, N);
    // merge_sort_v1<int>(A, N);
    // bubbleSort(A, 0, N-1);
    // bubbleSort2(A, N);
    printArray(A, N);
    // cout << partition2(A, 0, N-1) << endl;
    // qsort2(A, 0, N-1);

    // for (int i=0; i<N; ++i) cout << setw(4) << A[i]; cout << endl;

    return 0;
}
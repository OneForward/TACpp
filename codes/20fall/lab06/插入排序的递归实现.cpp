#include <iostream>
using namespace std;

void insert(int A[], int n) {
    int val = A[n], i;
    for ( i = n-1; i >= 1 && A[i] > val; --i) {
        A[i+1] = A[i];
    }
    
    if (A[i+1] > val) A[i+1] = val;
}

void insertSort(int A[], int n)
{
    if (n > 0)
    {
        insertSort(A, n - 1); // 递归实现，将前面n-1个元素排序好
        insert(A, n);         // 把第n个元素插入到前面n-1个元素中
    }
    else //递归的出口是n=0
        return;
}

int main()
{
    int n;
    cin >> n;

    int A[1005];
    for (int i = 1; i <= n; ++i) cin >> A[i];

    insertSort(A, n);
    for (int i = 1; i <= n; ++i) cout << A[i] << " ";
    
    return 0;
}
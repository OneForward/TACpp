#include <iostream>
#include <algorithm>

using namespace std;

int f(int* A,  int rht) {
    if (rht == 1) return A[0] + A[1];
    if (rht == 2) return A[0] + A[1] + A[2];
    int t1 = 2 * A[1] + A[0] + A[rht];
    int t2 = 2 * A[0] + A[rht-1] + A[rht];
    if (t1 < t2) return t1 + f(A, rht-2);
    return t2 + f(A, rht-2);
}

int main()
{
    int A[1005], n;
    cin >> n;
    
    for (int i = 0; i < n; ++i) cin >> A[i];
    
    sort(A, A+n);

    cout << f(A, n-1);

    return 0;
}

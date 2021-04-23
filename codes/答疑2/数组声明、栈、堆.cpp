#include <iostream>
using namespace std;

int main()
{
    const int N = 1<<28;
    int A[N];
    // int* A = new int[1<<28] {};
    int sum = 0;
    while (true) { sum += A[sum % 10]; };
    cout << sizeof(A);
    cout << sum;
}

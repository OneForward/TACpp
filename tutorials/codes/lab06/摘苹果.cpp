#include<iostream>
using namespace std;

int GetApple(int a[], int height, int n)
{
    int cnt = 0;
    for (int i = 0; i < n; ++i) { 
        if (a[i] <= height + 30) cnt++;
    }
    return cnt;
}

int main()
{
    int n, arr[105], height;
    cin >> n; 
    for (int i = 0; i < n; ++i) cin >> arr[i];
    cin >> height;

    cout << GetApple(arr, height, n);
    return 0;
}

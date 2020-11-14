#include <iostream>

using namespace std;

int main()
{
    int a, n, i, temp = 0, sum = 0;

    // cout << "Input a, n:";
    // a = 2; n = 5;
    cin >> a >> n;

    for(i = 1; i <= n; ++i)
    {
        temp = temp * 10 + a;
        sum += temp;
    }

    cout << sum << endl;

    return 0;
}

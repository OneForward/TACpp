#include <iostream>

using namespace std;

int main()
{

    int n; cin >> n;

    n %= 9;

    if (n == 0) n = 9;

    cout << n;

    return 0;
}

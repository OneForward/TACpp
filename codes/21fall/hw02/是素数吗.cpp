#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    bool isprime = n >= 2;
    for(int i = 2; i * i <= n; i++)
        if(n % i == 0) { isprime = false; break; }

    cout << (isprime ? "Yes" : "No");
    return 0;
}
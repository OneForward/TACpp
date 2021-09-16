#include <iostream>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;

    int sum = 0;
    for(int x = n; k and x >= 2; x--) {

        bool isprime = true;
        for(int i = 2; i * i <= x; i++)
            if(x % i == 0) { isprime = false; break; }
        
        if (isprime) {
            k--; sum += x;
            cout << x << " ";
        }
    }
    cout << sum;
    return 0;
}
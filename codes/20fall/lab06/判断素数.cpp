#include <iostream>

using namespace std;

bool isPrime(int n){
    if (n == 1) return false;
    for (int i = 2; i * i <= n; ++i) { 
        if (n % i == 0) return false;
    }
    return true;
}

int main()
{
    int m, n; cin >> m >> n;
    
    int cnt = 0;
    for (int x = m; x <= n; ++x) { 
        if (isPrime(x)) cnt++;
    }   
    cout << cnt;
    return 0;
}

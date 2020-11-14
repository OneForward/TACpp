#include <iostream>

using namespace std;

bool isPerfectNumber(int n){
    int sum = 0;
    for (int i = 1; i <= n / 2; ++i) { 
        if (n % i == 0) sum += i;
    }
    return sum == n;
}

int main(int argc, char const *argv[])
{
    int m, n; cin >> m >> n;
    
    bool found = false;
    for (int x = m; x <= n; ++x) { 
        if (isPerfectNumber(x)) { cout << x << " "; found = true; }
    }   
    if (!found) cout << -1;
    return 0;
}

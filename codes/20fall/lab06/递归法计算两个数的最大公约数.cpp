#include<iostream>
using namespace std;

int gcd(int m, int n) {
    if (m == 0) return n;
    return gcd(n % m, m);
}

int main()
{
    int m, n;
    
    cin >> m >> n;
    
    if (m <= 0 || n <= 0) printf("Input error!");
    else {
        int div = gcd(m, n); 
        printf("%d/%d", m / div, n / div);
    }
    return 0;
}
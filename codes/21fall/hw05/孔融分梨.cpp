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
    int div = gcd(m, n);
    if (div == -1 || div == 0) printf("Input error!");
    else printf("%d/%d", m / div, n / div);
    return 0;
}
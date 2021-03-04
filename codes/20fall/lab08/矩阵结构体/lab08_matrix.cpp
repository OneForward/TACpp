#include <iostream>

using namespace std;

const long long MOD = 1e9 + 7;

struct Matrix
{
    long long a, b, c, d;

    void disp() {
        printf("%lld %lld\n%lld %lld\n", a, b, c, d);
    }
};

Matrix times(const Matrix& lft, const Matrix& rht) {
    long long a = ((lft.a * rht.a + lft.b * rht.c) % MOD + MOD) % MOD;
    long long b = ((lft.a * rht.b + lft.b * rht.d) % MOD + MOD) % MOD;
    long long c = ((lft.c * rht.a + lft.d * rht.c) % MOD + MOD) % MOD;
    long long d = ((lft.c * rht.b + lft.d * rht.d) % MOD + MOD) % MOD;
    return Matrix{a, b, c, d};
}

Matrix fpower(Matrix x, long long n) {
    Matrix ans {1, 0, 0, 1}; // C++11 initializer list
    
    while (n) { 
        if (n % 2) ans = times(ans, x);
        x = times(x, x);
        n /= 2;
    }
    return ans;
}


int main()
{
    long long n; cin >> n;
    long long a, b, c, d; cin >> a >> b >> c >> d;

    Matrix A{a, b, c, d};
    Matrix ans = fpower(A, n);
    ans.disp();   

    return 0;
}
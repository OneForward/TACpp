#include <iostream>

using namespace std;

const long long MOD = 1e9 + 7;

struct Matrix
{
    long long a, b, c, d;

    void disp() {
        printf("%lld %lld\n%lld %lld\n", a, b, c, d);
    }

    Matrix& operator*=(const Matrix& rht) {
        long long a = ((this->a * rht.a + this->b * rht.c) % MOD + MOD) % MOD;
        long long b = ((this->a * rht.b + this->b * rht.d) % MOD + MOD) % MOD;
        long long c = ((this->c * rht.a + this->d * rht.c) % MOD + MOD) % MOD;
        long long d = ((this->c * rht.b + this->d * rht.d) % MOD + MOD) % MOD;
        *this = {a, b, c, d};
        return *this;
    }
};

Matrix fpower(Matrix x, long long n) {
    Matrix ans {1, 0, 0, 1}; // C++11 initializer list
    
    while (n) { 
        if (n % 2) ans *= x;
        x *= x;
        n /= 2;
    }
    return ans;
}


int main()
{
    freopen("in.txt", "r", stdin);
    
    long long n; cin >> n;
    long long a, b, c, d; cin >> a >> b >> c >> d;

    Matrix A{a, b, c, d};
    Matrix ans = fpower(A, n);
    ans.disp();   

    return 0;
}
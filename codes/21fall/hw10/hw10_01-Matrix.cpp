#include <iostream>

using namespace std;

using LL = long long;
const LL MOD = 1e9 + 7;

struct Matrix
{
    LL a, b, c, d;

    Matrix& operator*=(const Matrix& rht) {
        LL a = ((this->a * rht.a + this->b * rht.c) % MOD + MOD) % MOD;
        LL b = ((this->a * rht.b + this->b * rht.d) % MOD + MOD) % MOD;
        LL c = ((this->c * rht.a + this->d * rht.c) % MOD + MOD) % MOD;
        LL d = ((this->c * rht.b + this->d * rht.d) % MOD + MOD) % MOD;
        *this = {a, b, c, d};
        return *this;
    }
};

std::ostream& operator<<(std::ostream& os, const Matrix& M)
{
    os << M.a << " " 
       << M.b << "\n" 
       << M.c << " " 
       << M.d << "\n";
    return os;
}

Matrix fpower(Matrix x, LL n) {
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
    
    LL n; cin >> n;
    LL a, b, c, d; cin >> a >> b >> c >> d;

    Matrix A{a, b, c, d};
    
    Matrix ans = fpower(A, n);
    
    cout << ans;

    return 0;
}
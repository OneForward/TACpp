#include <iostream>
#include <chrono>
#include <iomanip>
// #include <ctime>
#include <thread>
using namespace std;

const long long MOD = 1e9 + 7;

struct Matrix
{
    long long a, b, c, d;

    void disp() {
        printf("%lld %lld\n%lld %lld\n", a, b, c, d);
    }
};

long long mod(long long x) {
    x %= MOD;
    if (x < 0) x += MOD;
    return x;
}

Matrix times(const Matrix& lft, const Matrix& rht) {
    long long a = mod(lft.a * rht.a + lft.b * rht.c);
    long long b = mod(lft.a * rht.b + lft.b * rht.d);
    long long c = mod(lft.c * rht.a + lft.d * rht.c);
    long long d = mod(lft.c * rht.b + lft.d * rht.d);
    return Matrix{a, b, c, d};
}

// Matrix times(const Matrix& lft, const Matrix& rht) {
//     long long a = ((lft.a * rht.a + lft.b * rht.c) % MOD + MOD) % MOD;
//     long long b = ((lft.a * rht.b + lft.b * rht.d) % MOD + MOD) % MOD;
//     long long c = ((lft.c * rht.a + lft.d * rht.c) % MOD + MOD) % MOD;
//     long long d = ((lft.c * rht.b + lft.d * rht.d) % MOD + MOD) % MOD;
//     return Matrix{a, b, c, d};
// }

Matrix fpower(Matrix x, long long n) {
    Matrix ans {1, 0, 0, 1}; // C++11 initializer list
    
    while (n) {
        if (n % 2) ans = times(ans, x);
        x = times(x, x);
        n /= 2;
    }
    // while (n--)
    // {
    //     ans  = times(ans, x);
    // }
    
    return ans;

}
void f() {
    long long n; cin >> n;
    long long a, b, c, d; cin >> a >> b >> c >> d;

    Matrix A{a, b, c, d};
    Matrix ans = fpower(A, n);
    ans.disp();
}

int main(int argc, char const *argv[])
{
    // freopen("in.txt", "r", stdin);
    // auto t_start = std::chrono::high_resolution_clock::now();

    long long n; cin >> n;
    long long a, b, c, d; cin >> a >> b >> c >> d;

    Matrix A{a, b, c, d};
    Matrix ans = fpower(A, n);
    ans.disp();   

    // auto t_end = std::chrono::high_resolution_clock::now();

    // std::cout << std::fixed << std::setprecision(2) 
    //         << "Wall clock time passed: "
    //         << std::chrono::duration<double, std::milli>(t_end-t_start).count()
    //         << " ms\n";
    
    return 0;
}

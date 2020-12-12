#include <iostream>
#include "Matrix.h"

using namespace std;


int main()
{
    
    long long n; cin >> n;
    long long a, b, c, d; cin >> a >> b >> c >> d;

    Matrix A{a, b, c, d};
    
    Matrix ans = fpower(A, n);
    
    cout << ans;

    return 0;
}
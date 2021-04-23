// 请在下方添加代码
/********** Begin *********/
#include<iostream>

using namespace std;

void encrypt(int x) {
    // x 是4位数
    int a = (x % 10 + 7) % 10; x /= 10; 
    int b = (x % 10 + 7) % 10; x /= 10;
    int c = (x % 10 + 7) % 10; x /= 10;
    int d = (x % 10 + 7) % 10; x /= 10;
    // d c b a -> b a d c
    if (b) cout << b;
    cout << a << d << c << " ";
}

void decrypt(int x) {
    // x 是4位数
    int a = (x % 10 + 3) % 10; x /= 10; 
    int b = (x % 10 + 3) % 10; x /= 10;
    int c = (x % 10 + 3) % 10; x /= 10;
    int d = (x % 10 + 3) % 10; x /= 10;
    // d c b a -> b a d c
    if (b) cout << b;
    cout << a << d << c << " ";
}

int main() 
{

    int n, m;
    cin >> n >> m;
    
    encrypt(n);
    decrypt(m);

    return 0;
}
/********** End **********/


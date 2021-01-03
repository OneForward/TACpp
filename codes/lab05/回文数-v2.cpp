#include <iostream>
using namespace std;

bool isreverse(int x, int B) {
    int ans = 0, x_copy = x;
    while (x) {
        ans = ans * B + x % B;
        x /= B;
    }
    return ans == x_copy;
}

void print(int x, int B, char end=' ') {
    char bases[10]; int len = 0;
    while (x) {
        bases[len++] = x % B < 10 ?  x % B + '0'  :  x % B - 10 + 'A' ;
        x /= B;
    }
    for (int i = len-1; i >= 0; --i) { 
        cout << bases[i];
    }
    cout << end;
}

int main()
{
    int B; 
    cin >> B;
    // B = 8;
    for (int x = 1; x <= 200; ++x) { 
        if (isreverse(x*x, B)) print(x, B), print(x*x, B, '\n');
    }
    return 0;
}

#include <iostream>

using namespace std;

void printInt(int x, int B){
    char bases[10]; int len = 0;
    while (x) {
        bases[len++] = x % B < 10 ?  x % B + '0'  :  x % B - 10 + 'A' ;
        x /= B;
    }
    for (int i = len-1; i >= 0; --i) { 
        cout << bases[i];
    }
}

int main(int argc, char const *argv[])
{
    int n, base; cin >> n >> base;
    
    printInt(n, base);
    
    return 0;
}

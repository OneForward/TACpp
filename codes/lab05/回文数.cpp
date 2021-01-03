#include <iostream>
using namespace std;

int main()
{
    int B; 
    cin >> B;
    // B = 8;
    for (int x = 1; x <= 200; ++x) { 
        char ybases[10]; int ylen = 0; int y = x*x;
        while (y) {
            ybases[ylen++] = y % B < 10 ?  y % B + '0'  :  y % B - 10 + 'A' ;
            y /= B;
        }
        bool isreverse = true;
        for (int i = 0; i <= ylen/2; ++i) { 
            if (ybases[i] != ybases[ylen-i-1]) { isreverse = false; break; }
        }
        if (!isreverse) continue;

        char xbases[10]; int xlen = 0; y = x;
        while (y) {
            xbases[xlen++] = y % B < 10 ?  y % B + '0'  :  y % B - 10 + 'A' ;
            y /= B;
        }
        for (int i = xlen-1; i >= 0; --i) cout << xbases[i]; cout << " ";
        for (int i = ylen-1; i >= 0; --i) cout << ybases[i]; cout << "\n";
    }
    
    return 0;
}

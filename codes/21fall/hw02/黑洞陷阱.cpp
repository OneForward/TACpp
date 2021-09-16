#include <iostream>
using namespace std;
int main()
{
    int x;
    cin >> x;

    for (int cnt = 1; x != 495; cnt++)
    {
        int a = x / 100, b = x / 10 % 10, c = x % 10, tmp;
        
        if (a < b) tmp = a, a = b, b = tmp;
        if (a < c) tmp = a, a = c, c = tmp;
        if (b < c) tmp = b, b = c, c = tmp;

        x = 99 * (a - c);

        int xmax = a * 100 + b * 10 + c, xmin = a + b * 10 + c * 100;
        printf("%d:%d-%d=%d\n", cnt, xmax, xmin, x);
    }
    return 0;
}
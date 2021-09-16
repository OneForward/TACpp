#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    printf("(%d, %d)和(%d, %d)之间的距离是：%.2f", x1, y1, x2, y2, 
            sqrt(pow(x1-x2, 2) + pow(y1-y2, 2)));
    return 0;
}

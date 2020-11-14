#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    printf("%d、%d、%d、%d的平均值是%.2f", a, b, c, d, (a+b+c+d)/4.);
    return 0;
}

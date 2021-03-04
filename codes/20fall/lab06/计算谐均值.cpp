#include <iostream>
#include <iomanip>
using namespace std;

double Calculate(double x, double y)
{
    return 2 * x * y / (x + y);
}

// 请不要修改main函数
int main()
{
    int t;
    double x, y;
    cin >> t;
    while (t--)
    {
        cin >> x >> y;
        cout << fixed << setprecision(3) << Calculate(x, y) << endl;
    }
}
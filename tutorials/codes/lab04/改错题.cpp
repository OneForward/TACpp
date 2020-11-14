// 请在下方添加代码
/********** Begin *********/
#include<iostream>
#include<iomanip>
using namespace std;
const double EPS = 1E-6;
int main() {
    int i, n, item;
    double e;
    e = 1;
    n = 1;
    do {
        item = 1;
        for (i = 1; i <= n; i++)
            item *= i;
        e += 1. / item;
        n++;
    } while (1./item >= EPS);
    cout << fixed << setprecision(6) << e << endl;
    return 0;
}
/********** End **********/


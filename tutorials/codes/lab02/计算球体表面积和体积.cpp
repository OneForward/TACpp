#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14;

int main(int argc, char const *argv[])
{
    int R; cin >> R;
    printf( "半径为%d的球体积为%.1f\n", R, 4 / 3. * PI * R * R * R );
    printf( "半径为%d的球体表面积为%.1f\n", R, 4 * PI * R * R);
    return 0;
}
 
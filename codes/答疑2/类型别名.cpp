#include <iostream>
using namespace std;

using Array10 = int[10];

using Func = int (*) (int, int);

using Func2 = auto (*)(int, int) -> int;

int func(int x, int y) {
    return x + y;
}

int main()
{
    Func2 f = func;
    cout << f(1, 2) << endl;

    // int[10] arr;
    Array10 arr1 = {1, 2, 3}, arr2 = {4, 5, 6};
    for (auto x: arr1) cout << x << " "; cout << endl;
    for (auto x: arr2) cout << x << " "; cout << endl;
    return 0;
}

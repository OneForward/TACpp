#include <iostream>
#include "Complex.hpp"

using namespace std;


int main()
{
    Complex x, y;
    cin >> x >> y;

    x += y; 
    cout << x << endl;

    y *= x;
    cout << y << endl;

    cout << x + y << endl;
    cout << y * x << endl;
    cout << x << endl;
    cout << y << endl;

    return 0;
}

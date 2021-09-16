#include <iostream>
using namespace std;
int main()
{
    int year;
    cin >> year;

    bool isleap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    cout << (isleap ? "Yes" : "No");
    return 0;
}
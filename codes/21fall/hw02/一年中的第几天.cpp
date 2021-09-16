#include <iostream>
using namespace std;

bool isleap(int year) {
    return (year % 4 == 0 && year % 100) || year % 400 == 0;
}

const int MONTHS[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int days(int year, int month, int day) {
    int count = 0;
    for (int m = 1; m < month; ++m) { 
        count += MONTHS[m-1];
    }
    count += day;
    if (isleap(year) && month > 2) count++;
    return count;
}

int main()
{
    // y-年，m-月,d-日，n-第几天
    int year, month, day, nth;
    cin >> year >> month >> day;

    nth = days(year, month, day);
    printf("%d-%d-%d是第%d天\n", year, month, day, nth);
    return 0;
}
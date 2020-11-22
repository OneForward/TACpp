#include <iostream>

using namespace std;

bool isleap(int year) {
    return (year % 4 == 0 && year % 100) || year % 400 == 0;
}

const int MONTHS[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int days(int year, int month, int day) {
    int count = 0;
    for (int y = 2000; y < year; ++y) { 
        count += 365;
        if (isleap(y)) count++;
    }
    for (int m = 1; m < month; ++m) { 
        count += MONTHS[m-1];
    }
    count += day;
    if (isleap(year) && month > 2) count++;
    return count;
}

int main()
{
    int year, month, day;
    // year = 2021, month = 9, day = 28;
    cin >> year >> month >> day;
    int count = days(year, month, day);

    // const char* WEEKS[] = { "日", "一", "二", "三", "四", "五", "六"};
    // cout << "星期" << WEEKS[(count+5) % 7];
    count = (count+5) % 7;
    if (count == 0) count = 7;
    cout << "星期" << count;
    return 0;
}

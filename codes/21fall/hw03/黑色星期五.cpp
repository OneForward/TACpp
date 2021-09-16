#include <iostream>
using namespace std;

const int MONTHS[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int weeks[7]{};

bool isleap(int year) {
    return (year % 4 == 0 && year % 100) || year % 400 == 0;
}

int main()
{
    int n;
    // cin >> n;
    n = 80;

    int count = 13; weeks[count%7] = 1; // 1900 年 1 月 13 日
    for (int y = 0; y < n; ++y) { 
        for (int m = 1; m <= 12; ++m) { 
            count += MONTHS[m];
            if (m == 2 && isleap(y + 1900)) count++;
            weeks[count%7]++;
        }
    }
    weeks[count%7]--; // 减去 (1900+n) 年 1 月 13 日
    for (int i = 1; i <= 7; ++i) { 
        cout << weeks[i == 7 ? 0 : i] << " ";
    }

    return 0;
}

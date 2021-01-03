#include <iostream>
#include <cstring>
using namespace std;

char *julian(int year, int day)
{
    if (day >= 370)
        return (NULL);
    char *p;
    int month1[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int month2[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    const char *month[] = {"Jan", "Feb", "Mar", "Apr", "May", "June", "July", "Aug", "Sept", "Oct", "Nov", "Dec"};
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        int i = 0;
        while (day > month1[i])
        {
            day = day - month1[i];
            i = i + 1;
        }
        strcpy(p, month[i]);
        *(p + 1) = ' ';
        if (day >= 1 && day <= 9)
        {
            *(p + 2) = '0';
            *(p + 3) = (day - '0');
        }
        else
        {
            *(p + 2) = day / 10 - '0';
            *(p + 3) = day % 10 - '0';
        }
        return (p);
    }

    else
    {
        int i = 0;
        while (day > month2[i])
        {
            day = day - month2[i];
            i = i + 1;
        }
        strcpy(p, month[i]);
        *(p + 1) = ' ';
        if (day >= 1 && day <= 9)
        {
            *(p + 2) = '0';
            *(p + 3) = (day - '0');
        }
        else
        {
            *(p + 2) = day / 10 - '0';
            *(p + 3) = day % 10 - '0';
        }
        return (p);
    }
}

int main()
{
    freopen("cases/作业7-Julian历法-作业1.txt", "r", stdin);

    int year, day;
    char *res;
    cin >> year >> day;
    res = julian(year, day);
    cout << res << endl;
    delete[] res;
    return 0;
}

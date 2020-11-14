#include <iostream>
#include <cstring>
using namespace std;

const char *MONTH[] = { 
    "Jan", "Feb", "Mar", "Apr", "May", "June", 
    "July", "Aug", "Sept", "Oct", "Nov", "Dec",
};

char ans[80];

bool isleap(int year)
{
    return (year % 4 == 0 && year % 100) || year % 400 == 0;
}

char *julian(int year, int day)
{
    if (day > 366 || (!isleap(year) && day == 366))
        return ans;

    int M[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isleap(year))
        M[1]++;

    int month, sum = 0;
    while (sum + M[month] < day)
        sum += M[month], month++;
    day -= sum;

    sprintf(ans, "%s %02d", MONTH[month], day);
    return ans;
}

int main()
{
    int year, day;
    char *res;
    cin >> year >> day;
    res = julian(year, day);
    cout << res << endl;
    return 0;
}
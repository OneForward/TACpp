#include <iostream>
#include "class.h"

Clock getTimeGap(Clock c1, Clock c2)
{
    int delta = abs(c1.timestamp - c2.timestamp);

    Clock ans;
    ans.timestamp = delta;
    return ans;
}

using namespace std;

int main()
{

    Clock c1, c2;

    int hour,  minute,  second;
    scanf("%d:%d:%d", &hour, &minute, &second);
    c1.SetTime(hour, minute, second);
    scanf("%d:%d:%d", &hour, &minute, &second);
    c2.SetTime(hour, minute, second);

    Clock ans = getTimeGap(c1, c2);

    ans.DisplayTime();

    return 0;
}
#include <iostream>
#include "Timer.h"
using namespace std;

int main()
{
    Timer timer;
    int hour, minute, second;
    cin >> hour >> minute >> second;

    timer.setTime(hour, minute, second);

    timer.showTime();
    timer.increase();
    timer.showTime();
    
    cin >> hour >> minute >> second;

    timer.setTime(hour, minute, second);

    timer.showTime();
    timer.increase();
    timer.showTime();

    return 0;
}

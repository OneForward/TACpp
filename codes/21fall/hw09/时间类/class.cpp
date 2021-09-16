#include "class.h"
#include <cstdio>

void Clock::SetTime(int hour, int minute, int second)
{
    timestamp = hour * 3600 + minute * 60 + second;
};

void Clock::DisplayTime()
{
    int t = timestamp;
    int second = t % 60;
    t /= 60;
    int minute = t % 60;
    t /= 60;
    int hour = t % 60;
    printf("%02d:%02d:%02d\n", hour, minute, second);
};

Clock::Clock(){};
Clock::~Clock(){};

#ifndef __TIMER_H__
#define __TIMER_H__

#include <iostream>
#include <iomanip>

struct Timer
{
    int timestamp;
    
    void setTime(int hour, int minute, int second) {
        timestamp = hour * 3600 + minute * 60 + second;
    }

    void increase() {
        timestamp++;
        timestamp %= 86400;
    }

    void showTime() {
        int t = timestamp;
        int second = t % 60; t /= 60;
        int minute = t % 60; t /= 60;
        int hour = t % 60; 
        std::printf("%02d:%02d:%02d\n", hour, minute, second);
        
        // or you can try `iomanip` for output format
        // std::cout << std::setw(2) << std::setfill('0') << hour << ":";
        // std::cout << std::setw(2) << std::setfill('0') << minute << ":";
        // std::cout << std::setw(2) << std::setfill('0') << second << "\n";
    }

};


#endif // __TIMER_H__

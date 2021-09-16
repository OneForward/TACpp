#include <iostream>
#include <iomanip>
using namespace std;

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
        printf("%02d:%02d:%02d\n", hour, minute, second);
        
        // or you can try `iomanip` for output format
        // cout << setw(2) << setfill('0') << hour << ":";
        // cout << setw(2) << setfill('0') << minute << ":";
        // cout << setw(2) << setfill('0') << second << "\n";
    }

};

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

#ifndef CLASS_H
#define CLASS_H

class Clock
{
public:
    int timestamp;
    void SetTime(int hh, int mm, int ss);
    void DisplayTime();
    Clock();
    ~Clock();
};


#endif /* CLASS_H */
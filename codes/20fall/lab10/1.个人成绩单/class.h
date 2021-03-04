#ifndef CLASS_H
#define CLASS_H
#include <cstring>
#include <iostream>

using namespace std;

class PersonScore
{
public:
    PersonScore(char* i=NULL, char* n=NULL, int m=0, int e=0, int c=0);
    ~PersonScore();
    void GiveValue(int m, int e, int c);
    void Display();
    int GetHigh();
    int GetLow();
    bool isMathPass();
    bool isEnglishPass();
    bool isCSPass();

private:
    char id[80];
    char name[80];
    int math;
    int English;
    int CS;
};



#endif /* CLASS_H */
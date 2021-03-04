#include "class.h"

using namespace std;


PersonScore::PersonScore(char* i, char* n, int m, int e, int c) {
    // Your code goes here
}

PersonScore::~PersonScore() {
    
}

void PersonScore::GiveValue(int m, int e, int c){
    math = m; English = e; CS = c;
}

void PersonScore::Display(){
    printf("%s %s %d %d %d\n", "00000000", "name", math, English, CS);
}

int PersonScore::GetHigh(){
    return max(math, max(English, CS));
}

int PersonScore::GetLow(){
    return min(math, min(English, CS));
}

bool PersonScore::isMathPass(){
    return math >= 60;
}

bool PersonScore::isEnglishPass(){
    return English >= 60;
}

bool PersonScore::isCSPass(){
    return CS >= 60;
}
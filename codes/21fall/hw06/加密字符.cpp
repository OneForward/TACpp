#include <iostream>
using namespace std;

const int pattern []  = { 8, 7, 3, 4, 9, 6, 2 };

void encrypt(char* s) {
    size_t p = 0;
    while (*s) {
        *s = 32 + (*s + pattern[p] - 32) % 91;
        s++; p++; p %= 7;
    }
}


void decrypt(char* s) {
    size_t p = 0;
    while (*s) {
        *s = 32 + (*s - pattern[p] - 32 + 122 - 32 + 1) % 91;
        s++; p++; p %= 7;
    }
}

int main()
{
    char line[105];
    cin.getline(line, sizeof(line));

    encrypt(line); cout << line << endl;
    decrypt(line); cout << line << endl;

    return 0;
}

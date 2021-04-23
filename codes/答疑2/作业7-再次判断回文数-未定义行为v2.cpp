#include <iostream>
#include <cstring>
using namespace std;

bool ispalindrome(const char* s) {
    int len = strlen(s);
    while ((len - 2) >= 0)
    {
        // 以下这句语句是 undefined behavior
        if ((*(s++)) != (*(s + (len -= 2))))
            return false;
        // s++; // ok
    }
    return true;
}

int main() {
    cout << boolalpha << ispalindrome("abcba") << endl;
}
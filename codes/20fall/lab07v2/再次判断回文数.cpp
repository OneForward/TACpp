#include <iostream>
#include <cstring>
using namespace std;

bool func(char array[ ], int len);

int main() {
    char ch[20];
    bool result;

    cin >> ch;

	//此处填补几行代码
    cout << (func(ch, strlen(ch)) ? "Yes" : "No");

    return 0;
}

bool func(char array[ ], int len) {
    for (int i = 0; i < len/2; ++i) { 
        if (array[i] != array[len-i-1]) return false;
    }
    return true;
}
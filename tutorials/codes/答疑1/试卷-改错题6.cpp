#include <iostream>

using namespace std;

char* func(char* s) {
    for (int k = 0; *(k+s); ++k) *(k+s) += 1;
    return s;
}

int main()
{
    const char* multi_strings[] = {
        "Jan",
        "Feb",
        "Hello ",
    };

    for (int i = 0; i < 3; ++i) { 
        cout << multi_strings[i] << endl;
    }
    // cout << func(s) << endl;
    return 0;
}

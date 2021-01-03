#include <iostream>
using namespace std; 

int main() {
    
    const char* s = "hello";
    char something[] = "something";

    const char* multi_strings[] = { 
        "Jan",
        "Feb",
        "Mar",
    };

    for (int i = 0; i < sizeof(multi_strings) / 8; ++i) { 
        cout << multi_strings[i] << endl;
    }

}
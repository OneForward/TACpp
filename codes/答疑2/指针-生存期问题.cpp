#include <iostream>
#include <cstring>

using namespace std;

// string* f() {
//     string s = "hello";
//     string* ps = &s;
//     return ps;
// }

// string* f() {
//     string* s = new string("hello");
//     return s;
// }

// char s[100]; // global, ok
char* f( ) {
    char s[] = "hello"; // fail, local array
    // char s[100]; strcpy(s, "hello"); // fail, local array
    // char* s; strcpy(s, "hello"); // fail, no mem allocated
    // char* s = new char[10];  strcpy(s, "hello"); // ok
    return s;
}

int main()
{
    cout << f();
    return 0;
}

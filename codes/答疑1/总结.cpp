#include <iostream>
using namespace std;

int main() {

    const char* s = "hello";
    char something[] = "something";
    cout << s << endl << something << endl;

    const char* multi_strings[] = {
        "Jan",
        "Feb",
        "Mar",
    };

    for (int i = 0; i < (int)sizeof(multi_strings) / 8; ++i) {
        cout << multi_strings[i] << endl;
    }

    int A[10] = {1, 2, 3};

    for (auto x: A) {
        cout << x << " ";
    }

}

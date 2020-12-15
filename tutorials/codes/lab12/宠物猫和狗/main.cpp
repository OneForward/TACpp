#include <iostream>
#include "class.h"

using namespace std;

// Do not modify this file!

int main()
{
    Pet *pets[4];
    const char *names[4] = { "aaa", "bbb", "ccc", "ddd"};

    for (int k = 0; k < 4; ++k) {
        if ( k % 2 ) pets[k] = new Cat(names[k], k);
        else pets[k] = new Dog(names[k], k);
    }

    for (int k = 0; k < 4; ++k)
        pets[k]->print();

    return 0;
}
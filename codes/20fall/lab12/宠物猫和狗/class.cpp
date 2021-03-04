#include "class.h"


// Your code goes here

#include <cstring>
#include <cstdio>

void Cat::print() const {
    printf("I am %s's cat! I am %d years old.\n", name, age);
}

void Dog::print() const {
    printf("I am %s's dog! I am %d years old.\n", name, age);
}

Pet::Pet(const char* _name, int age): age{age} {
    strcpy(name, _name);
}

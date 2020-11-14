#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const char* Metric[] = {
    "millimeters", "centimeters", "decimeters", "meters",
};

const char* British[] = {
    "inches", "feet", "yards",
};

const float Scale[] = {
    39.4, 3.28, 1.0936
};


int main()
{
    char unit1[80], unit2[80], yes; float x; 
    
    while (true) {
        printf("Please input:\n");
        scanf("How many %s are in %f %s ?\n", unit1, &x, unit2);
        
        for (int i = 0; i < 4; ++i) { 
            for (int j = 0; j < 3; ++j) { 
                if (strcmp(Metric[i], unit2) == 0 && strcmp(British[j], unit1) == 0) {
                    x *= Scale[j] / pow(10, 3-i);
                }
            }
        }
        printf("%4g\n", x);
        
        printf("Go on?(y/n):");
        scanf("%c\n", &yes);

        if (yes == 'n') break;
    }
    return 0;
}

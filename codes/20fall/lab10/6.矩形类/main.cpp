#include <iostream>
#include "class.h"
using namespace std;

int main(){

    float x1, y1, x2, y2;

    cin >> x1 >> y1 >> x2 >> y2;
    Rectangle rect1 {x1, y1, x2, y2};

    cin >> x1 >> y1 >> x2 >> y2;
    Rectangle rect2 {x1, y1, x2, y2};

    printf("%.2f\n", rect1.area());
    printf("%.2f\n", rect2.area());
    printf("%.2f\n", intersection(rect1, rect2).area());

    return 0;
}
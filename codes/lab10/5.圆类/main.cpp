#include <iostream>
#include "class.h"


using namespace std;

int main(){
    Circle c1, c2;
    float r, x, y;

    cin >> r >> x >> y;
    c1.setParameters(r, {x, y});

    cin >> r >> x >> y;
    c2.setParameters(r, {x, y});

    isOverlapped(c1, c2);

    return 0;
}
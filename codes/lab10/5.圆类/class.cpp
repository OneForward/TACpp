#include "class.h"
#include <cstdio>
#include <cmath>

void Circle::setParameters(float r, const Point& p) { radius = r, center = p;  }


float dist(const Point& p1, const Point& p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

float area(float a, float b, float c) {
    float r = (a + b + c) / 2;
    return sqrt( r * (r - a) * (r - b) * (r - c) ); 
}

void isOverlapped(const Circle& lft, const Circle& rht) {
    float d = dist(lft.center, rht.center);
    if (d > lft.radius + rht.radius) printf("NO\n");
    else {
        float S = area(lft.radius, rht.radius, d);
        printf("%.2f\n", 4 * S / d);
    }
}
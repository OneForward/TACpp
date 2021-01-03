#include "class.h"

Point::Point(double x, double y): x{x}, y{y} {}

Point::Point(Point& p) {
    *this = p;
}

Point::~Point() {}

void Point::SetX(double nx) { x = nx; };
void Point::SetY(double ny) { y = ny; };
void Point::SetPoint(double nx, double ny) { x = nx; y = ny; };
void Point::SetPoint(Point &np) { *this = np; };
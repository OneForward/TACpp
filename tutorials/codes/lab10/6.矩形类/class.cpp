#include "class.h"
#include <cmath>

double Rectangle:: area() { return fabs((x1 - x2) * (y1 - y2)); }

Rectangle intersection(const Rectangle& lft, const Rectangle& rht) {
    return Rectangle { fmax(lft.x1, rht.x1), fmax(lft.y1, rht.y1), fmin(lft.x2, rht.x2), fmin(lft.y2, rht.y2)  };
}
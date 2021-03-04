#ifndef CLASS_H
#define CLASS_H


struct Rectangle
{
    double x1, y1, x2, y2; // 保证 (x1, y1) < (x2, y2)
    double area() ;
    friend Rectangle intersection(const Rectangle& lft, const Rectangle& rht);
};

#endif /* CLASS_H */
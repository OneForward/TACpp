#ifndef CLASS_H
#define CLASS_H

struct Point
{
    float x, y;
};


class Circle
{
private:
    float radius;
    Point center;
    friend void isOverlapped(const Circle& lft, const Circle& rht);
public:
    void setParameters(float r, const Point& p);
};



#endif /* CLASS_H */
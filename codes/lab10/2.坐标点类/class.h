#ifndef CLASS_H
#define CLASS_H

class Point
{
public:
    Point(double nx=0.0, double ny=0.0);
    Point(Point &np);
    ~Point();
    void SetX(double nx);
    void SetY(double ny);
    void SetPoint(double nx, double ny);
    void SetPoint(Point &np);
    double x;
    double y;
};



#endif /* CLASS_H */
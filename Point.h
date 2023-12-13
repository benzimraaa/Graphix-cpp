#ifndef POINT_H
#define POINT_H

class Point
{    
public:
    int x;
    int y;
    Point(int x, int y);
    ~Point();
    Point operator+(const Point& p);
    Point& operator+=(Point& p);
    Point operator*(const float& f);
    Point& operator*=(const float& f);
};

#endif // POINT_H

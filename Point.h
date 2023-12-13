#ifndef POINT_H
#define POINT_H

#include <ostream>

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
    Point rotate(const float& angle);
    Point rotate(const float& angle, const Point& origin);
    // operator<<
    friend std::ostream& operator<<(std::ostream& os, const Point& p);

};

#endif // POINT_H

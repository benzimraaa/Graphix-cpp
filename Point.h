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
    Point operator-(const Point& p);
    Point& operator+=(Point& p);
    Point& operator-=(Point& p);
    Point operator*(const float& f) const;
    Point operator/(const float& f) const;
    Point& operator*=(const float& f);
    Point rotate(const float& angle);
    Point rotate(const float& angle, const Point& origin);
    float dot(const Point& p);
    float norm2() const;
    float length();
    void setLength(float length);
    Point projectionVector(const Point& p);


    // operator<<
    friend std::ostream& operator<<(std::ostream& os, const Point& p);

};

#endif // POINT_H

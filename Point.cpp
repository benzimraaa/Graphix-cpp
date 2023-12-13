#include "Point.h"

Point::Point(int x, int y): x(x), y(y) {}

Point::~Point() {}

Point Point::operator+(const Point& p)
{
    return Point(this->x + p.x, this->y + p.y);
}

Point& Point::operator+=(Point& p)
{
    this->x += p.x;
    this->y += p.y;
    return *this;
}

Point Point::operator*(const float &f)
{
    return Point(static_cast<int>(this->x * f), 
                 static_cast<int>(this->y * f));
}

Point& Point::operator*=(const float &f)
{
    this->x = static_cast<int>(this->x * f);
    this->y = static_cast<int>(this->y * f);
    return *this;
}
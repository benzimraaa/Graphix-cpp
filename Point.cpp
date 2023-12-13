#include "Point.h"
#include <valarray>

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

Point Point::rotate(const float &angle)
{
    int x = static_cast<int>(this->x * cos(angle) - this->y * sin(angle));
    int y = static_cast<int>(this->x * sin(angle) + this->y * cos(angle));
    return Point(x,y);
}

Point Point::rotate(const float &angle, const Point &origin)
{   
    int dx = this->x - origin.x;
    int dy = this->y - origin.y;

    int x = static_cast<int>(dx * cos(angle) - dy * sin(angle));
    int y = static_cast<int>(dx * sin(angle) + dy * cos(angle));
    return Point(x , y) + origin;
}

std::ostream &operator<<(std::ostream &os, const Point &p)
{
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

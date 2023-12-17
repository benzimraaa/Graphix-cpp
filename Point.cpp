#include "Point.h"
#include <valarray>

Point::Point(int x, int y): x(x), y(y) {}

Point::~Point() {}

Point Point::operator+(const Point& p)
{
    return Point(this->x + p.x, this->y + p.y);
}

Point Point::operator-(const Point& p)
{
    return Point(this->x - p.x, this->y - p.y);
}

Point& Point::operator+=(Point& p)
{
    this->x += p.x;
    this->y += p.y;
    return *this;
}

Point &Point::operator-=(Point &p)
{
    this->x -= p.x;
    this->y -= p.y;
    return *this;
}

Point Point::operator*(const float &f) const
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

float Point::dot(const Point &p)
{
    return this->x * p.x + this->y * p.y;
}

float Point::norm2() const
{
    return pow(this->x, 2) + pow(this->y, 2);
}

float Point::length()
{
    return sqrt(norm2());
}

void Point::setLength(float length)
{
    float norm = this->length();
    // devide by len and cast to int
    this->x = static_cast<int>(this->x / norm * length);
    this->y = static_cast<int>(this->y / norm * length);
}

Point Point::projectionVector(const Point &p)
{
    return p * (this->dot(p) / p.norm2());
}

std::ostream &operator<<(std::ostream &os, const Point &p)
{
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

#include "Ball.h"
#include <iostream>

Ball::Ball(int radius, Point center, Color color):
    radius(radius), Entity(center, color)
{   
    vector<Point> Points;
    for (int x = -radius; x <= radius; x++)
    {
        int y = sqrt(radius * radius - x * x);
        Points.push_back(Point(x, y));
        Points.push_back(Point(x, -y));
    }
    
    setPoints(Points);

    Point speed = Point(10, 8);
    this->updateFunction = [speed](Point p) { return p + speed; };
    std::cout << -3 << std::endl;
}

Ball::~Ball()
{
}

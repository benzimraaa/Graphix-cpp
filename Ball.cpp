#include "Ball.h"
#include <iostream>

Ball::Ball(int radius, Point center, Color color, Point speed):
    radius(radius), Entity(center, color), speed(speed)
{   
    vector<Point> Points;
    for (int x = -radius; x <= radius; x++)
    {
        int y = sqrt(radius * radius - x * x);
        Points.push_back(Point(x, y));
        Points.push_back(Point(x, -y));
    }
    
    setPoints(Points);

}

Ball::~Ball()
{
}

void Ball::update()
{
    for (auto &p : points)
    {
        p += speed;
    }
}

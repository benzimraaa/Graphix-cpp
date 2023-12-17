#include "Ball.h"
#include <iostream>

Ball::Ball(int radius, Point center, Color color, Point speed):
    radius(radius),center(center), Entity(center, color, string("Ball")), speed(speed)
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
    center += speed;
    for (auto &p : points)
    {
        p += speed;
    }
}

void Ball::collideWithRod(Rod& rod){
    // vector w is the rod vector
    auto ends = rod.getEnds();
    Point w = ends.second - ends.first;

    // vector v is the ball velocity vector
    Point v = speed;

    // vector k is the projection of v onto w
    Point k = v.projectionVector(w);

    setSpeed(k * 2 - v);

}

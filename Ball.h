#pragma once
#include "Entity.h"
#include "Rod.h"

class Ball : public Entity
{
private:
    Point center;
    int radius;
    Point speed;
public:
    Ball(int radius, 
            Point center = Point(0, 0), 
            Color color = Color(255, 0, 0),
            Point speed = Point(10, 8)
            );
    ~Ball();
    void update() override; 
    Point getCenter() { return center; }
    int getRadius() { return radius; };
    Point getSpeed() { return speed; };
    void setSpeed(Point speed) { this->speed = speed; };
    // func for if ball collides with rod change speed
    void collideWithRod(Rod& rod);

};
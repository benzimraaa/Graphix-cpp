#include "Entity.h"
#include <iostream>

Entity::Entity(vector<Point> points, Color color, Point position, string type) : 
    points(std::move(points)), color(color), position(position), type(type) 
{
}

Entity::Entity(Point position, Color color, string type) : 
    color(color), position(position), type(type)
{
}

Entity::~Entity()
{
}

vector<Point> Entity::getPoints()
{
    auto copy = this->points;
    for (auto &p : copy)
    {
        p *= scaler;
        p += position;
        // rotate around position
        p = p.rotate(rotator, position);
    }
    return copy;
}

void Entity::translate(Point translation)
{
    this->position += translation;
}

void Entity::update()
{}

#include "Entity.h"

Entity::Entity(vector<Point> points, Color color, Point position):
    points(std::move(points)), color(color), position(position)
{
}

Entity::Entity(Point position, Color color):
    color(color), position(position)
{
}

Entity::~Entity()
{
}


vector<Point> Entity::getPoints() 
{   
    auto copy = this->points;
    for (auto& p: copy)
    {   
        p *= scaler;
        p += position;
    }
    return copy;
}

void Entity::translate(Point translation)
{
    this->position += translation;
}

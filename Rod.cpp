#include "Rod.h"
#include <iostream>

Rod::Rod(Point start, Point end, int width, Color color) : 
    freeStart(start-end), fixEnd(Point(0,0)), width(width), color(color),
    Entity(end, color, string("Rod"))
{
    setModel();
}

Rod::~Rod()
{
}
void Rod::setModel()
{   
    Point end = fixEnd;
    Point start = freeStart;
    Point diff = start - end;
    Point normal = Point(diff.y, -diff.x);
    // Point normal(-diff.y, diff.x);
    normal.setLength(float(width));
    Point upRight = end + normal;
    Point upLeft = freeStart + normal;

    points.push_back(end);
    points.push_back(upRight);
    points.push_back(upLeft);
    points.push_back(freeStart);

}

pair<Point, Point> Rod::getEnds()
{   
    auto ends = Entity::getPoints();
    return pair<Point, Point>(ends[0], ends[3]);
}

void Rod::update()
{
}
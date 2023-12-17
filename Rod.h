#pragma once    
#include "Entity.h"

class Rod : public Entity
{
private:
    Point freeStart;
    Point fixEnd;
    int width;
    Color color;
public:
    Rod(Point freeStart, Point fixEnd, int width=8, Color color=Color(255, 0, 0));
    ~Rod();
    void update() override;
    void setModel();
    pair<Point, Point> getEnds();
};



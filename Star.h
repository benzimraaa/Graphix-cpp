#ifndef STAR_H
#define STAR_H

#include "Entity.h"

class Star : public Entity
{
private:
    int vertices;
    int innerRadius;
    int outerRadius;

public:
    Star(int vertices, int innerRadius, int outerRadius, Point center = Point(0, 0), Color color = Color(255, 0, 0));
    ~Star();
    vector<Point> getPoints();
};

#endif // STAR_H


#include "Star.h"
#include <cmath>

Star::Star(int vertices, int innerRadius, int outerRadius, Point center, Color color)
    :Entity(center, color)
{
    this->vertices = vertices;
    this->innerRadius = innerRadius;
    this->outerRadius = outerRadius;
    vector<Point> sPoints;
    float angle = M_PI / vertices;
    for (int i = 0; i < vertices*2; i++)
    {
        int r = (i % 2 == 0 ? outerRadius : innerRadius);
        int x = r * cos(i * angle);
        int y = r * sin(i * angle);
        Point p(x, y);
        sPoints.push_back(p);
    }
    setPoints(sPoints);
}

Star::~Star()
{
}

// vector<Point> Star::getPoints()
// {
//     vector<Point> sPoints;
//     float angle = M_PI / vertices;
//     for (int i = 0; i < vertices*2; i++)
//     {
//         int r = (i % 2 == 0 ? outerRadius : innerRadius);
//         int x = r * cos(i * angle);
//         int y = r * sin(i * angle);
//         Point p(x, y);
//         sPoints.push_back(p);
//     }
//     setPoints(sPoints);
//     return Entity::getPoints();
// }

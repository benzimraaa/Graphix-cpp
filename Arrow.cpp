#include "Arrow.h"

Arrow::Arrow(Point p0, Point p1, Color color):
    Entity(p0, color)
{
    vector<Point> points;
    // arctan
    const float ANGLE = M_PI / 6;
    const float LENGTH = 10;

    float angle = atan2(p1.y - p0.y, p1.x - p0.x);
    float arrow1Angle = angle + M_PI - ANGLE;
    float arrow2Angle = angle + M_PI + ANGLE;

    // arrow1 (x,y)
    int x1 = p1.x + LENGTH * cos(arrow1Angle);
    int y1 = p1.y + LENGTH * sin(arrow1Angle);

    // arrow2 (x,y)
    int x2 = p1.x + LENGTH * cos(arrow2Angle);
    int y2 = p1.y + LENGTH * sin(arrow2Angle);

    Point arrow1(x1, y1);
    Point arrow2(x2, y2);

    points.push_back(p0);
    points.push_back(p1);
    points.push_back(arrow1);
    points.push_back(arrow2);
    points.push_back(p1);

    setPoints(points);

}

Arrow::~Arrow()
{
}

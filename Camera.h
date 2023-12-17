#pragma once
#include "Point.h"


class Camera
{
private:
    Point pos;
    double zoomFactor;
    double rotationAngle;
public:
    Camera();
    ~Camera();
    Point getPos();
    void moveBy(Point delta);
    void transform(Point& p);
    void zoom(double factor);
    void rotate(double angle);
};



#pragma once
#include "Point.h"


class Camera
{
private:
    Point pos;
public:
    Camera();
    ~Camera();
    Point getPos();
    void moveBy(Point delta);
    void transform(Point& p);
};



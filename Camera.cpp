#include "Camera.h"

Camera::Camera(): pos(Point(0, 0))
{
}


Camera::~Camera()
{
}
Point Camera::getPos()
{
    return pos;
}

void Camera::moveBy(Point delta)
{
    pos = pos + delta;
}

void Camera::transform(Point& p)
{
    p -= pos;
}
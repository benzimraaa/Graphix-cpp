#include "Camera.h"
#include <valarray>
#include <iostream>

Camera::Camera(): pos(Point(0, 0)), zoomFactor(1), rotationAngle(0), dragStart(0, 0), dragEnd(0, 0)
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
    p *= zoomFactor;
    int x = p.x;
    p.x = static_cast<int>(p.x * cos(rotationAngle) - p.y * sin(rotationAngle));
    p.y = static_cast<int>(x * sin(rotationAngle) + p.y * cos(rotationAngle));
}

void Camera::zoom(double factor)
{
    zoomFactor *= factor;
}

void Camera::rotate(double angle)
{
    rotationAngle += angle;
}

void Camera::relativeMove()
{
    Point delta = dragEnd - dragStart;
    if (abs(delta.x) < 1000 && abs(delta.y) < 1000){
        delta.x = -delta.x;
        delta.rotate(-rotationAngle);
        moveBy(delta/zoomFactor);
        // std::cout << "delta: " << delta << " ,"<< dragEnd - dragStart<<std::endl;
        dragStart = dragEnd;
    }

    
}

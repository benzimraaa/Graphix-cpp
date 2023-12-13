#include "Entity.h"

class Ball : public Entity
{
private:
    int radius;
public:
    Ball(int radius, Point center = Point(0, 0), Color color = Color(255, 0, 0));
    ~Ball();
};
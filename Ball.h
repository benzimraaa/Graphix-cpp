#include "Entity.h"

class Ball : public Entity
{
private:
    int radius;
    Point speed;
public:
    Ball(int radius, 
            Point center = Point(0, 0), 
            Color color = Color(255, 0, 0),
            Point speed = Point(10, 8)
            );
    ~Ball();
    void update() override; 
};
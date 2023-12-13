#include "Entity.h"

class Arrow : public Entity
{
public:
    Arrow(Point p0, Point p1, Color color = Color(255, 0, 0));
    ~Arrow();
};
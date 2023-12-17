#include "Collision.h"


bool isColliding(Entity* e1, Entity* e2)
{
    if (e1->getType() == "Ball" && e2->getType() == "Rod" ){
        swap(e1, e2);
    }
    if (e1->getType() == "Rod" && e2->getType() == "Ball" ){
        auto rod = dynamic_cast<Rod*>(e1);
        auto ball = dynamic_cast<Ball*>(e2);

        // compute the line equation
        auto ends = rod->getEnds();
        auto v = ends.second - ends.first;
        auto w = ball->getCenter() - ends.first;
        float t = v.dot(w) / v.dot(v);
        if (t < 0.0f) t = 0.0f;
        if (t > 1.0f) t = 1.0f;

        // compute the closest point on the line
        auto closest = ends.first + v*t;
        // compute the distance from the ball center to the closest point
        float d = (ball->getCenter() - closest).length();
        // calc if velocity is toward the rod
        auto velocity = ball->getSpeed();
        Point lineNormal = Point(v.y, -v.x);
        auto velocityTowardRod = velocity.dot(lineNormal) > 0;
        return d <= ball->getRadius() && velocityTowardRod;        
    }
    else if(e1->getType() == "DynamicStar" && e2->getType() == "DynamicStar")
    {
        auto star1 = dynamic_cast<DynamicStar*>(e1);
        auto star2 = dynamic_cast<DynamicStar*>(e2);
        auto center1 = star1->getPosition();
        auto center2 = star2->getPosition();
        auto radius1 = star1->getMaxRadius();
        auto radius2 = star2->getMaxRadius();
        auto distance = (center1 - center2).length();
        return distance <= radius1 + radius2;
        

    }
    return false;

}
#pragma once
#include "Star.h"


class DynamicStar : public Star{
private:
    float rotationSpeed;
    int radiusSpeed;
    int max_radius;
    int radiusDiff;
public:
    DynamicStar(int vertices, int innerRadius, int outerRadius, 
                Point center = Point(0, 0), 
                Color color = Color(255, 0, 0),
                float rotationSpeed = 0.1,
                int radiusSpeed = 1,
                float max_radius = 100);
    ~DynamicStar();
    void update();
    int getMaxRadius(){return max_radius;};
};

class StarSky{
private:
    vector<DynamicStar> stars;

public:
    StarSky(int nStars, Point xRange=Point(-10000,10000), Point yRange=Point(-10000,10000));
    ~StarSky();
    void update();
    vector<DynamicStar> getStars(){return stars;};  
    
};
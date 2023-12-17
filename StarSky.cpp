#include "StarSky.h"
#include <random>
#include "Collision.h"
#include <iostream>

DynamicStar::DynamicStar(int vertices, int innerRadius, int outerRadius, Point center, Color color, float rotationSpeed, int radiusSpeed, float max_radius):
    Star(vertices, innerRadius, outerRadius, center, color)
{
    this->rotationSpeed = rotationSpeed;
    this->radiusSpeed = radiusSpeed;
    this->max_radius = max_radius;
    this->radiusDiff = outerRadius - innerRadius;
    setType("DynamicStar");
}

DynamicStar::~DynamicStar()
{
}

void DynamicStar::update()
{   
    int range = max(max_radius - radiusDiff, 1);
    innerRadius = (innerRadius + radiusSpeed) % range;
    outerRadius = (outerRadius + radiusSpeed) % max_radius;
    rotateRotator(rotationSpeed);
    starModel();
    
}

StarSky::StarSky(int nStars, Point xRange, Point yRange)
{
    // uniform distribution of color 
    std::uniform_int_distribution<int> colorDist(0, 255);
    // uniform distribution of radius
    std::uniform_int_distribution<int> radiusDist(1, 700);
    // uniform distribution of rotation speed
    std::uniform_real_distribution<float> rotationSpeedDist(0, 1);
    // uniform distribution of radius speed
    std::uniform_int_distribution<int> radiusSpeedDist(0, 20);
    // uniform distribution of max radius
    std::uniform_int_distribution<int> maxRadiusDist(50, 400);
    // uniform distribution of vertices
    std::normal_distribution<float> verticesDist(10, 7);
    // uniform distribution of inner radius ratio
    std::normal_distribution<float> innerRadiusDist(.5,.5);
            // uniform distribution of center
    std::uniform_int_distribution<int> centerDistX(xRange.x, xRange.y);
    std::uniform_int_distribution<int> centerDistY(yRange.x, yRange.y);

    std::default_random_engine generator;
    int i = 0;
    int nTries = 0;
    while (i < nStars && nTries < 20*nStars)
    {
        nTries++;
        int vertices = max(static_cast<int> (verticesDist(generator)),2);
        int maxRadius = maxRadiusDist(generator);
        int outerRadius = radiusDist(generator) % maxRadius;
        int innerRadius = static_cast<int> (innerRadiusDist(generator) * outerRadius);
        float rotationSpeed = rotationSpeedDist(generator);
        int radiusSpeed = radiusSpeedDist(generator);
        int x = centerDistX(generator);
        int y = centerDistY(generator);
        Point center(x, y);
        Color color(colorDist(generator), colorDist(generator), colorDist(generator));
        DynamicStar newStar(vertices, innerRadius, outerRadius, center, color, rotationSpeed, radiusSpeed, maxRadius);
        bool isCollidingStar = false;
        for (auto &star : stars)
        {
            if (isColliding(&newStar, &star)){
                isCollidingStar = true;
                break;
            }
            
        }
        if (isCollidingStar){
            continue;
        }
        stars.push_back(newStar);
        i++;

    }
    std::cout << "Stars generated: " << stars.size() << " number of tries: " << nTries << std::endl;
    
}

StarSky::~StarSky()
{
}

void StarSky::update()
{
    for (auto &star : stars)
    {
        star.update();
    }
}



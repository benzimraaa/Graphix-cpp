// gard for multiple inclusion
#pragma once

#include <vector>
#include "Point.h"
#include "Color.cpp"
#include <functional>

using namespace std;

class Entity
{
private:
        vector<Point> points;
        Color color;
        Point position;
        float scaler = 1.0f;
        float rotator = 0.0f;
protected:
        function<Point(Point)> updateFunction = [](Point p) { return p; };

public:
        Entity(vector<Point> points, Color color=Color(255, 0, 0), Point position=Point(0, 0));
        Entity(Point position=Point(0, 0), Color color=Color(255, 0, 0));
        ~Entity();
        Point getPosition() const { return position; }
        void setPosition(Point position) { this->position = position; }
        void increasePosition(Point position) { this->position += position; }
        vector<Point> getPoints();
        void setPoints(vector<Point> points) { this->points = points; }
        Color getColor() const { return color; }
        void setColor(Color color) { this->color = color; }
        float getScaler() const { return scaler; }
        void setScaler(float scaler) { this->scaler = scaler; }
        void scaleScaler(float scaler) { this->scaler *= scaler; }
        void translate(Point translation);
        float getRotator() const { return rotator; }
        void setRotator(float angle) { this->rotator = angle;}
        void rotateRotator(float angle) { this->rotator += angle; }
        void update();

};


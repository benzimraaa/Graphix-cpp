#include <vector>
#include "Point.h"
#include "Color.cpp"

using namespace std;

class Entity
{
private:
    vector<Point> points;
    Color color;
    Point position;
    float scaler = 1.0f;
public:
    Entity(vector<Point> points, Color color=Color(255, 0, 0), Point position=Point(0, 0));
    Entity(Point position=Point(0, 0), Color color=Color(255, 0, 0));
    ~Entity();
    Point getPosition() const { return position; }
    void setPosition(Point position) { this->position = position; }
    vector<Point> getPoints();
    void setPoints(vector<Point> points) { this->points = points; }
    Color getColor() const { return color; }
    void setColor(Color color) { this->color = color; }
    float getScaler() const { return scaler; }
    void setScaler(float scaler) { this->scaler = scaler; }
    void translate(Point translation);

};


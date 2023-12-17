#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include "Color.cpp"
#include "Point.h"
#include "Camera.h"

class Graphix {
public:
    Graphix(int width, int height, Camera* cam = nullptr);
    ~Graphix();

    void putPixel(int x, int y, const Color& color = Color(0, 0, 0));
    void drawLine(const Point& p1, const Point& p2, const Color& color = Color(255, 255, 255));
    void drawEllipse(const Point& center, int radiusX, int radiusY, const Color& color = Color(255, 255, 255));
    void drawPolygon(const std::vector<Point>& points, const Color& color = Color(255, 255, 255));  // Draw a polygon with the given points
    void render();
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    void cohordinateTransformation(Point& p);
    void rotateSpace(float angle);
    void clear();
    Uint32 lastUpdateTime = SDL_GetTicks();
    


private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    int width;
    int height;
    std::vector<std::vector<Color>> pixels;
    Camera* cam;
};

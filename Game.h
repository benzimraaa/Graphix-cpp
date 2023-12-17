#include "Graphix.h"
#include "Arrow.h"
#include "StarSky.h"
#include "Ball.h"
#include "Camera.h"
#include "Rod.h"


class Game {
public:
    Game(int width, int height);

    void handleEvents();
    void handleMouseHover(const SDL_MouseMotionEvent& motionEvent);
    void handleMouseClick(int x, int y);
    void updateModel(SDL_Event event);
    void run();
    void composeFrame();

private:
    Graphix gfx;
    bool quit;
    bool isDragging = false;
    Camera cam;
    StarSky starSky;
    
};


#include "Game.h"
#include <iostream>


Game::Game(int width, int height) : 
    cam(),
    gfx(width, height, &cam)
    
{
    // Arrow arrow(Point(0, 0), Point(100, 300), Color(255, 0, 0));
    // Star star(100, 20, -1);
    
    this->entity = new Ball(10);
    auto rand_radius = [](){
        return rand() % 100 + 10;
    };
    auto rand_color = [](){
        return Color(rand() % 255, rand() % 255, rand() % 255);
    };
    
    Balls.emplace_back(rand_radius(), Point(0, 0), rand_color(), Point(1, 1));
    Balls.emplace_back(rand_radius(), Point(0, 0), rand_color(), Point(1, -1));
    Balls.emplace_back(rand_radius(), Point(0, 0), rand_color(), Point(-1, 1));
    Balls.emplace_back(rand_radius(), Point(0, 0), rand_color(), Point(-1, -1));
    Balls.emplace_back(rand_radius(), Point(0, 0), rand_color(), Point(1, 0));
    Balls.emplace_back(rand_radius(), Point(0, 0), rand_color(), Point(0, 1));
    Balls.emplace_back(rand_radius(), Point(0, 0), rand_color(), Point(-1, 0));
    Balls.emplace_back(rand_radius(), Point(0, 0), rand_color(), Point(0, -1));
    Balls.emplace_back(rand_radius(), Point(0, 0), rand_color(), Point(2, 1));
    Balls.emplace_back(rand_radius(), Point(0, 0), rand_color(), Point(2, -1));
}

void Game::handleEvents() {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            
            else if (event.type == SDL_KEYDOWN){
                updateModel(event);
            }
            if (event.type == SDL_MOUSEWHEEL){
                updateModel(event);
            }
        }
}


void Game::handleMouseHover(const SDL_MouseMotionEvent& motionEvent) {
    
    // Point p1(motionEvent.x, motionEvent.y);
    // Point p2(100, 100);
    // gfx.clear();
    // gfx.drawLine(p1, p2);
    // gfx.render();
    
}

void Game::handleMouseClick(int x, int y)
{
    // Point p1(x, y);
    // gfx.clear();
    // Star star(15, 100, -200, p1);
    // gfx.drawPolygon(star.getPoints(), Color(255, 0, 0));
    // gfx.drawEllipse(p1, 200, 200, Color(255, 250, 0));
}

void Game::updateModel(SDL_Event event)
{   
    auto isKeyPressed = [](SDL_Scancode key) {
        const Uint8* state = SDL_GetKeyboardState(NULL);
        return state[key];
    };
    const int speed = 10;
    if (isKeyPressed(SDL_SCANCODE_RIGHT)) {
        cam.moveBy(Point(speed, 0));
    } 
    if (isKeyPressed(SDL_SCANCODE_LEFT)) {
        cam.moveBy(Point(-speed, 0));
    } 
    if (isKeyPressed(SDL_SCANCODE_UP)) {
        cam.moveBy(Point(0, speed));
    } 
    if (isKeyPressed(SDL_SCANCODE_DOWN)) {
        cam.moveBy(Point(0, -speed));
    } 
    if (isKeyPressed(SDL_SCANCODE_PAGEUP)){
        entity->setRotator(entity->getRotator() + M_PI/7);
    } 
    if (isKeyPressed(SDL_SCANCODE_PAGEDOWN)){
        entity->setRotator(entity->getRotator() - M_PI/7);
    } 
    if (event.type == SDL_MOUSEWHEEL){
        if (event.wheel.y > 0){
            entity->setScaler(entity->getScaler() * 1.05);
        }
        else if (event.wheel.y < 0){
            entity->setScaler(entity->getScaler() * .95);
        }
    } 

}

void Game::run() {
    // Game loop
    quit = false;
    composeFrame();
    while (!quit) {
        // updateModel();
        // Present the renderer
        handleEvents();
        composeFrame();
        gfx.render();
    }
}

void Game::composeFrame()
{   
    // handleMouseClick(300, 300);
    gfx.clear();
    entity->update();
    gfx.drawPolygon(entity->getPoints(), entity->getColor());

    for (auto& ball : Balls){
        ball.update();
        gfx.drawPolygon(ball.getPoints(), ball.getColor());
    }
    
    // gfx.drawEllipse(Point(0,0), 200, 200, Color(255, 250, 0));

    // // gfx.clear();
    // // Star star(5, 100, 200, Point(300, 300));
    // // gfx.drawPolygon(star.getPoints(), Color(255, 0, 0));
    // Point p1(-100, 100);
    // Point p2(-100, -100);
    // Point p3(100, 100);
    // Point p4(100, -100);
    // // gfx.drawLine(p1, p2);
    // // gfx.drawLine(p3, p2);
    // // gfx.drawLine(p3, p1);
    // for (int i = - 5; i < 5; i++){
    //     gfx.putPixel(p1.x+i, p1.y, Color(255, 0, 0));
    //     gfx.putPixel(p2.x+i, p2.y, Color(0, 255, 0));
    //     gfx.putPixel(p3.x+i, p3.y, Color(0, 0, 255));
    //     gfx.putPixel(p4.x+i, p4.y, Color(255, 255, 0));
    // }
    
}

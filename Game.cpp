#include "Game.h"
#include <iostream>
#include "BallSpawn.h"
#include "Collision.h"


Game::Game(int width, int height) : 
    cam(),
    gfx(width, height, &cam),
    starSky(2000)
    
{
    
}

void Game::handleEvents() {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            updateModel(event);
            
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
        cam.rotate(0.1);
        // rod1->rotateRotator(0.1);
    } 
    if (isKeyPressed(SDL_SCANCODE_PAGEDOWN)){
        cam.rotate(-0.1);
        // rod2->rotateRotator(0.1);
    } 
    if (event.type == SDL_MOUSEWHEEL){
        if (event.wheel.y > 0){
            cam.zoom(1.05);
        }
        else if (event.wheel.y < 0){
            cam.zoom(0.95);
        }
    } 
    if (event.type == SDL_MOUSEBUTTONDOWN){
        if (event.button.button == SDL_BUTTON_LEFT){
            isDragging = true;
            cam.dragStart = Point(event.button.x, event.button.y);
        }
    }
    if (event.type == SDL_MOUSEBUTTONUP){
        if (event.button.button == SDL_BUTTON_LEFT){
            isDragging = false;
        }
    }
    if (isDragging){
        cam.dragEnd = Point(event.button.x, event.button.y);
        cam.relativeMove();
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
    starSky.update();
    for (auto &star : starSky.getStars())
    {
        gfx.drawPolygon(star.getPoints(), star.getColor());
    }
    
}

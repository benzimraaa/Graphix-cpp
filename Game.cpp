#include "Game.h"
#include <iostream>


Game::Game(int width, int height) : 
    gfx(width, height),
    star(10, 100, -200)
    
{}

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
        star.translate(Point(speed, 0));
    } if (isKeyPressed(SDL_SCANCODE_LEFT)) {
        star.translate(Point(-speed, 0));
    } if (isKeyPressed(SDL_SCANCODE_UP)) {
        star.translate(Point(0, speed));
    } if (isKeyPressed(SDL_SCANCODE_DOWN)) {
        star.translate(Point(0, -speed));
    } if (event.type == SDL_MOUSEWHEEL){
        if (event.wheel.y > 0){
            star.setScaler(star.getScaler() * 1.05);
        }
        else if (event.wheel.y < 0){
            star.setScaler(star.getScaler() * .95);
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
    gfx.drawPolygon(star.getPoints(), star.getColor());
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

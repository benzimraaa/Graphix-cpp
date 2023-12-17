#pragma once
#include "Ball.h"


void BallSpawn(vector<Ball>& balls, int numBalls){
    auto rand_radius = [](){
        return rand() % 70 + 5;
    };
    auto rand_color = [](){
        return Color(rand() % 255, rand() % 255, rand() % 255);
    };

    auto rand_speed = [](){
        return Point(rand() % 12 - 6, rand() % 12 - 6);
    };
    
    auto rand_starting_point = [](){
        return Point(rand() % 200 - 100, rand() % 200 - 100);
    };

    for (int i = 0; i < numBalls; i++){
        balls.emplace_back(rand_radius(), rand_starting_point(), rand_color(), rand_speed());
    }
}


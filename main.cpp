#include "Game.h"
#include <iostream>

int main() {
    Game game(900, 700);
    std::cout << "Game created\n";
    game.run();

    return 0;
}

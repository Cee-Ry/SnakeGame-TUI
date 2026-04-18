#include "../header/game.hpp"
#include "../header/func.hpp"

#include <iostream>
#include <thread>
#include <chrono>

Functions func;

int main() {
    func.hideCursor();

    while (!snake.isDead) {
        map.set();
        snake.at();
        map.show();
        
        std::this_thread::sleep_for(std::chrono::milliseconds(snake.speed));

        func.clearScreen();
    }
    
    return 0;
}

#include "../header/game.hpp"
#include "../header/func.hpp"

// #include <iostream> is in func.hpp
#include <thread>
#include <chrono>

Functions func;

int main() {
    func.hideCursor();

    while (!snake.isDead) {
        map.set();
        snake.at();
        snake.move();
        snake.passThroughWalls();
        map.show();
        //snake.move();
        
        std::this_thread::sleep_for(std::chrono::milliseconds(snake.speed));

        func.clearScreen();
        std::cout << "X: " << snake.headX 
            << "\nY: " << snake.headY << '\n';
    }
    
    return 0;
}

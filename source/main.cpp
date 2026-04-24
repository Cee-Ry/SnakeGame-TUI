#include "../headers/map.hpp"
#include "../headers/snake.hpp"
#include "../headers/food.hpp"
#include <ncurses.h>
#include <iostream>

int main() {
    initscr();
    curs_set(0);
    
    map.set();

    while (snake.inGame) {
        std::cout << "X: " << food.X << "\tY: " << food.Y << "\n\rscore: " << food.score << "\n\r";
        snake.goTo();
        map.update();
        map.display();
        // std::cout << "Y: " << snake.headY <<
            // "\tX: " << snake.headX << "\n\r";
        snake.nav();

        clear();
        refresh();
    }

    endwin();

    return 0;
}

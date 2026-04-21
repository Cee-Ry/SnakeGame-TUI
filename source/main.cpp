#include "../headers/map.hpp"
#include "../headers/snake.hpp"
#include <iostream>
#include <ncurses.h>

int main() {
    initscr();
    
    map.set();

    while (true) {
        snake.goTo();
        map.update();
        map.display();
        std::cout << "X: " << snake.headX -1 << 
            "Y: " << snake.headY - 1 << "\n\r";

        std::cin.get();

        clear();
        refresh();
    }
    endwin();

    return 0;
}

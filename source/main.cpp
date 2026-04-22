#include "../headers/map.hpp"
#include "../headers/snake.hpp"
#include <ncurses.h>
#include <iostream>

int main() {
    initscr();
    curs_set(0);
    
    map.set();

    while (snake.inGame) {
        snake.goTo();
        map.update();
        map.display();
        std::cout << "Y: " << snake.headY <<
            "\tX: " << snake.headX << "\n\r";
        snake.nav();

        clear();
        refresh();
    }

    endwin();

    return 0;
}

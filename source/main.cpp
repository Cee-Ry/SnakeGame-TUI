#include "../headers/map.hpp"
#include "../headers/snake.hpp"
#include <ncurses.h>

int main() {
    initscr();
    curs_set(0);
    
    map.set();

    while (true) {
        snake.goTo();
        map.update();
        map.display();
        snake.nav();

        clear();
        refresh();
    }

    endwin();

    return 0;
}

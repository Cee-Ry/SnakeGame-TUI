#include <ncurses.h>
#include "../headers/game_api.hpp"

GameMap map;

int main() {
    initscr();
    curs_set(0);
    noecho();
    start_color();

    init_pair(1, COLOR_RED, COLOR_RED);

    bool play {true};
    
    while (play) {
        clear();
        refresh();

        map.draw();
        getch();
    }

    endwin();
    return 0;
}

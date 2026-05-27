#include "../headers/game_api.hpp"
#include <ncurses.h>

void GameMap::draw() {
    mvprintw(0, (COLS / 2) - 12,"== == === === === === ==");
    mvprintw(1, (COLS / 2) - 12," === SNAKE GAME TUI === ");
    mvprintw(2, (COLS / 2) - 12,"== == === === === === ==");
    mvprintw(3, (COLS / 2) - (38 / 2),"--- Press ESC to view other Option ---");

    attron(COLOR_PAIR(1));
    for (int i {height}; i < (LINES - (LINES % 2)); i++) {
        mvprintw(i, width, "##");
        mvprintw(i, (COLS - (COLS % 2)) - width, "##");

        for (int j {width}; j < (COLS - (COLS % 2)) - width; j++) {
            mvprintw(4, j, "#");
            mvprintw(LINES - 1, j, "#");
        }
    }
    attroff(COLOR_PAIR(1));
}

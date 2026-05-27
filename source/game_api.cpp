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

void GameMap::update(int &Y, int &X) {
    attron(COLOR_PAIR(2));
    mvprintw(Y, X, "%s", s.head.c_str());
    attroff(COLOR_PAIR(2));
}

void GameMap::nav(int &Y, int &X) {
    int key = getch();

    switch(key) {
        case KEY_UP:
            dir = UP;
            break;

        case KEY_DOWN:
            dir = DOWN;
            break;

        case KEY_LEFT:
            dir = LEFT;
            break;

        case KEY_RIGHT:
            dir = RIGHT;
            break;

        default:
            break;
    }

    switch (dir) {
        case UP:
            --Y;
            break;

        case DOWN:
            ++Y;
            break;

        case LEFT:
            X -= 2;
            break;

        case RIGHT:
            X += 2;
            break;

        default:
            break;
    }
}


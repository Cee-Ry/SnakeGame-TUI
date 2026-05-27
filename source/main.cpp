#include <ncurses.h>
#include "../headers/game_api.hpp"

GameMap map;
Snake snake;

void choices(int &sel, bool &play, bool &run);

int main() {
    initscr();
    curs_set(0);
    noecho();
    cbreak();
    start_color();
    keypad(stdscr, true);

    init_pair(1, COLOR_RED, COLOR_RED);
    init_pair(2, COLOR_GREEN, COLOR_GREEN);

    bool run {true};
    bool escape {};
    bool play {};

    snake.Y = (LINES / 2);
    snake.X = (COLS / 2) - ((COLS / 2) % 2);
    int &speed = snake.speed;
    int sel {0};
    
    while (run) {
        choices(sel, play, run);

        while (play) {
            timeout(speed);
            printw("%d | %d", snake.Y, snake.X);

            mvprintw(0, (COLS / 2) - 12,"== == === === === === ==");
            mvprintw(1, (COLS / 2) - 12," === SNAKE GAME TUI === ");
            mvprintw(2, (COLS / 2) - 12,"== == === === === === ==");
            mvprintw(3, (COLS / 2) - (38 / 2),"--- Press ESC to view other Option ---");

            map.draw();
            map.update(snake.Y, snake.X);
            map.nav(snake.Y, snake.X);

            clear();
            refresh();
        }
    }

    endwin();
    return 0;
}

void choices(int &sel, bool &play, bool &run) {
    std::string options[3] {"Play", "Options", "Exit"};

        mvprintw(0, (COLS / 2) - 12,"== == === === === === ==");
        mvprintw(1, (COLS / 2) - 12," === SNAKE GAME TUI === ");
        mvprintw(2, (COLS / 2) - 12,"== == === === === === ==");

        for (int i {}; i < 3; i++) {
            if (i == sel) {
                attron(A_REVERSE);
                mvprintw(5 + i, (COLS / 2) - options[i].length() / 2, options[i].c_str());
                attroff(A_REVERSE);
            } else {
                mvprintw(5 + i, (COLS / 2) - options[i].length() / 2, options[i].c_str());
            }
        }

        int key = getch();
        switch (key) {
            case KEY_UP:
                if (sel != 0) --sel;
                break;

            case KEY_DOWN:
                if (sel != sizeof(options)/sizeof(options[0]) - 1) ++sel;
                break;

            case '\n': // Enter key
                if (sel == 0) {
                    play = true;
                } else if (sel == 1) {
                    // Options menu logic can be implemented here
                } else if (sel == 2) {
                    run = false;
                }
                break;

            default:
                break;
        }


}

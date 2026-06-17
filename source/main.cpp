#include <ncurses.h>
#include <ctime>
#include <cstdlib>
#include "../headers/game_api.hpp"

GameMap map;

void choices(int &sel, bool &play, bool &run);
void showOptions();

int main() {
    initscr();
    curs_set(0);
    noecho();
    cbreak();
    start_color();
    keypad(stdscr, true);

    if (!has_colors()) {
        endwin();
        printf("Terminal does not support colors.\n");
        return 1;
    }

    init_pair(1, COLOR_RED, COLOR_RED);
    init_pair(2, COLOR_GREEN, COLOR_GREEN);

    std::srand(static_cast<unsigned>(std::time(nullptr)));

    bool run {true};
    bool play {};
    int sel {0};

    map.reset();

    while (run) {
        if (!play) {
            clear();
            choices(sel, play, run);
            refresh();
            if (!run) {
                break;
            }
            if (play) {
                map.reset();
            }
        }

        while (play) {
            timeout(map.s.speed);

            map.nav();
            if (map.pause) {
                map.pause = false;
                play = false;
                clear();
                refresh();
                break;
            }

            map.update();
            clear();
            map.draw();
            refresh();

            if (map.gameOver) {
                timeout(-1);
                clear();
                map.draw();
                map.drawGameOver();
                refresh();
                int key;
                do {
                    key = getch();
                } while (key != '\n' && key != KEY_ENTER && key != 27);
                play = false;
            }
        }
    }

    endwin();
    return 0;
}

void showOptions() {
    clear();
    mvprintw(2, (COLS / 2) - 10, "=== OPTIONS ===");
    mvprintw(4, (COLS / 2) - 18, "Use the arrow keys to move the snake.");
    mvprintw(5, (COLS / 2) - 18, "Eat food (*) to grow and score points.");
    mvprintw(6, (COLS / 2) - 18, "Avoid hitting the wall or your own tail.");
    mvprintw(7, (COLS / 2) - 18, "Press ESC while playing to return to the menu.");
    mvprintw(9, (COLS / 2) - 16, "Press any key to return.");
    refresh();
    getch();
}

void choices(int &sel, bool &play, bool &run) {
    std::string options[3] {"Play", "Options", "Exit"};

    mvprintw(0, (COLS / 2) - 12, "== == === === === === ==");
    mvprintw(1, (COLS / 2) - 12, " === SNAKE GAME TUI === ");
    mvprintw(2, (COLS / 2) - 12, "== == === === === === ==");

    for (int i {}; i < 3; i++) {
        if (i == sel) {
            attron(A_REVERSE);
            mvprintw(5 + i, (COLS / 2) - static_cast<int>(options[i].length()) / 2, options[i].c_str());
            attroff(A_REVERSE);
        } else {
            mvprintw(5 + i, (COLS / 2) - static_cast<int>(options[i].length()) / 2, options[i].c_str());
        }
    }

    int key = getch();
    switch (key) {
        case KEY_UP:
            if (sel > 0) {
                --sel;
            }
            break;

        case KEY_DOWN:
            if (sel < static_cast<int>(sizeof(options) / sizeof(options[0])) - 1) {
                ++sel;
            }
            break;

        case '\n':
        case KEY_ENTER:
            if (sel == 0) {
                play = true;
            } else if (sel == 1) {
                showOptions();
            } else if (sel == 2) {
                run = false;
            }
            break;

        default:
            break;
    }
}

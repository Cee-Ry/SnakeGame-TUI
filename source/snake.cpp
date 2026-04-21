#include "../headers/snake.hpp"
#include "../headers/map.hpp"
#include <ncurses.h>

Snake snake;

void Snake::goTo() {
    switch (moveTo) {
        case UP:
            --headY;
            if (headY == 0) {
                headY = map.height - 2;
            }

            break;
        case DOWN:
            ++headY;
            if (headY == map.height - 1) {
                headY = 1;
            }

            break;
        case RIGHT:
            headX += 2;
            headX1 = headX + 1;
            if (headX1 == map.width - 3) {
                headX = 2;
                headX1 = headX + 1;
            }

            break;
        case LEFT:
            headX -= 2;
            headX1 = headX + 1;
            if (headX == 1) {
                headX = map.width - 4;
                headX1 = headX + 1;
            }

            break;
        default:
            break;
    }
}

void Snake::nav() {
    timeout(speed);
    char key;

    key = getch();

    if (key == 'w' || key == 'W') {
        moveTo = UP;
    } else if (key == 's' || key == 'S') {
        moveTo = DOWN;
    } else if (key == 'd' || key == 'D') {
        moveTo = RIGHT;
    } else if (key == 'a' || key == 'A') {
        moveTo = LEFT;
    }
}

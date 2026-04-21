#include "../headers/snake.hpp"
#include "../headers/map.hpp"

Snake snake;
Snake::Directions moveTo = Snake::LEFT;

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
            ++headX;
            headX1 = headX + 1;
            if (headX1 == map.width - 2) {
                headX = 2;
                headX1 = headX + 1;
            }

            break;
        case LEFT:
            --headX;
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

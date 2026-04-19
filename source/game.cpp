#include "../header/game.hpp"

#include <iostream>

Map map;
Snake snake;

void Map::set() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            map[i][j] = ' ';
        }
    }

    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            map[0][j] = border;
            map[height - 1][j] = border;
        }

        map[i][0] = border;
        map[i][width - 1] = border;
        map[i][1] = border;
        map[i][width - 2] = border;
    }
}


void Map::show() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (map[i][j] == border) {
                std::cout << "\033[41;31m" << map[i][j] << "\033[0m";
            } else if (map[i][j] == snake.SnakeHead) {
                std::cout << "\033[44;34m" << map[i][j] << "\033[0m";
            } else {
                std::cout << map[i][j];
            }
            
        }
        std::cout << "\n";
    }
}

void Snake::at(){
   map.map[headY][headX] = SnakeHead;
   map.map[headY][headX + 1] = SnakeHead;
}

void Snake::move() {
    direction moveTo = RIGHT;

    switch (moveTo) {
        case UP:
            headY--;
            break;
        case DOWN:
            headY++;
            break;
        case LEFT:
            headX--;
            break;
        case RIGHT:
            headX++;
            break;
        default:
            break;
    }
}

void Snake::passThroughWalls() {
    if (headY == 0) {
        headY = map.height - 2;
    } else if (headY == map.height - 1) {
        headY = 1;
    } else if (headX == 1) {
        headX = map.width - 4;
    } else if (headX + 1 == map.width - 2) {
        headX = 2;
    }
      
}

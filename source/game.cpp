#include "../header/game.hpp"
#include <iostream>

Map map;

void Map::set() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            map[i][j] = ' ';
        }
    }

    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            map[0][j] = borderU;
            map[height - 1][j] = borderD;
        }

        map[i][0] = borderL;
        map[i][width - 1] = borderR;
    }
}


void Map::show() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            std::cout << map[i][j];
        }
        std::cout << "\n";
    }
}

void Snake::at(){
   map.map[headY][headX] = SnakeHead;
}
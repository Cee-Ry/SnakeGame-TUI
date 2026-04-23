#include "../headers/map.hpp"
#include "../headers/snake.hpp"
#include "../headers/food.hpp"
#include <iostream>

Map map;

void Map::set() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || 
                j == 1 || j == width - 1 || j == width - 2) {
                outline[i][j] = wall;
            } else {
                outline[i][j] = empty;
            }
        }
    }
}

void Map::update() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || 
                j == 1 || j == width - 1 || j == width - 2) {
                outline[i][j] = wall;
            } else {
                outline[i][j] = empty;
            }
        }
    }

    outline[snake.headY][snake.headX] = snake.head;
    outline[snake.headY][snake.headX1] = snake.head;

    while (food.isEaten) {
        food.Y = food.fruitY();
        food.X = food.fruitX();
    
    food.isEaten = false;
    }

    outline[food.Y][food.X] = food.fruit;
    outline[food.Y][food.X + 1] = food.fruit;
    std::cout << "FY: " << food.Y << "\n\rFX: " << food.X << "\n\r";

    if (snake.headY == food.Y && 
            (snake.headX == food.X || snake.headX == food.X + 1)) {
        food.isEaten = true;
    }

}

void Map::display() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            std::cout << outline[i][j];
        }
        std::cout << "\n\r";
    }
}

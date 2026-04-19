#include "../headers/allIncludes.hpp"
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
}

void Map::display() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            std::cout << outline[i][j];
        }
        std::cout << '\n';
    }
}
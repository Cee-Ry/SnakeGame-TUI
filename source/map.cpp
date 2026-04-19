#include "../headers/allIncludes.hpp"
Map map;


void Map::set() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || 
                j == 1 || j == width - 1 || j == width - 2) {
                border[i][j] = wall;
            } else {
                border[i][j] = empty;
            }
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            std::cout << border[i][j];
        }
        std::cout << '\n';
    }
}
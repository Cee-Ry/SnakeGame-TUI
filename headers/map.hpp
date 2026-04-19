#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>

struct Map {
    static const int width = 50;
    static const int height = 20;

    std::string border[height][width];
    std::string wall = "\033[41;31m#\033[0m";
    std::string empty = " ";

    void set();
    void show();
}; 

extern Map map;

#endif
#ifndef MAP_HPP
#define MAP_HPP

#include <string>

struct Map {
    static const int width = 52;
    static const int height = 20;

    std::string outline[height][width];
    std::string wall = "\033[41;31m#\033[0m";
    std::string empty = " ";

    void set();
    void display();
    void update();
}; 

extern Map map;

#endif

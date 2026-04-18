#ifndef GAME_HPP
#define GAME_HPP

#include <string>

struct Map {
    static const int width = 80;
    static const int height = 30;
    char map[height][width];

    char border {'#'};

    void set();
    void show();
};

struct Snake {
    Map nav;
    char SnakeHead {'O'};
    char SnakeBody {'*'};
    
    int headX {nav.width /2};
    int headY {nav.height /2};
    
    void at();
};

extern Map map;
extern Snake snake;

#endif

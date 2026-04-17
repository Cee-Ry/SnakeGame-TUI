#ifndef GAME_HPP
#define GAME_HPP

#include <string>

struct Map {
    static const int width = 60;
    static const int height = 20;
    char map[height][width];

    char borderL {'|'};
    char borderR {'|'};
    char borderU {'-'};
    char borderD {'-'};

    void set();
    void show();
};

struct Snake {
    char SnakeHead {'*'};
}

#endif

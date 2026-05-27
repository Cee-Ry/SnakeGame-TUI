#pragma once

#include <string>
#include <vector>
#include <ncurses.h>

enum Directions {Stay, UP, DOWN, LEFT, RIGHT};

struct Snake {
    std::vector<std::string> tails;

    std::string head {"HH"};
    std::string tail {"TT"};
    int Y {};
    int X {};
    int speed {100};
};

struct GameMap {
    Snake s;
    Directions dir;

    int width {16};
    int height {4};

    void draw();
    void update(int &Y, int &X);
    void nav(int &Y, int &X);
};

#pragma once

#include <deque>
#include <utility>
#include <string>
#include <ncurses.h>

enum Directions {Stay, UP, DOWN, LEFT, RIGHT};

struct Snake {
    std::deque<std::pair<int,int>> body;
    char head {'@'};
    char tail {'o'};
    int speed {100};
    int score {};
};

struct GameMap {
    Snake s;
    Directions dir {RIGHT};

    int border {2};
    int top {4};

    bool pause {};
    bool gameOver {};

    int foodY {};
    int foodX {};

    void reset();
    void draw();
    void update();
    void nav();
    void placeFood();
    bool hitWall(int y, int x) const;
    bool hitSelf(int y, int x) const;
    void drawBorders() const;
    void drawScore() const;
    void drawGameOver() const;
};

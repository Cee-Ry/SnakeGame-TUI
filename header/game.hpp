#ifndef GAME_HPP
#define GAME_HPP

struct Map {
    static const int width = 80;
    static const int height = 30;
    char map[height][width];

    char border {'#'};

    void set();
    void show();
};

struct Snake {
    bool isDead {false};
    int speed {100};

    Map position;
    char SnakeHead {'O'};
    char SnakeBody {'*'};
    
    int headX {position.width /2};
    int headY {position.height /2};
    
    void at();
    void move();
    void passThroughWalls();
    
    enum direction {
        STAY,
        UP,
        DOWN,
        LEFT,
        RIGHT
    };
};

extern Map map;
extern Snake snake;

#endif

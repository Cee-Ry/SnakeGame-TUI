#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "allIncludes.hpp"

struct Snake {
    std::string head {"\033[44;34m-\033[0m"};

    int headY {map.height / 2};
    int headX {map.width / 2};
    int headX1 {headX + 1};
    
};

extern Snake snake;

#endif

#ifndef ALLINCLUDES_HPP
#define ALLINCLUDES_HPP

#include "../headers/map.hpp"
#include "../headers/snake.hpp"

// === Here are Global/Universal Functions
#include <iostream>
#include <limits>

inline void clearScreen() {
    std::cout << "\033[2J\033[1;1H";
}
inline void hideCursor() {
    std::cout << "\033[?25l";
}

inline void cleanCin() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

#endif

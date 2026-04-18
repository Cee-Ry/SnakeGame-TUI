#ifndef func_hpp
#define func_hpp

#include <iostream>
#include <limits>

struct Functions {
    void clearScreen() {
        std::cout << "\033[2J\033[1;1H";
    }
    
    void hideCursor() {
        std::cout << "\033[?25l";
    }
    
    void cleanCin() {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
};

#endif

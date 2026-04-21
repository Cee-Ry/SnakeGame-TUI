#include "../headers/map.hpp"
#include <iostream>

int main() {
    
    map.set();

    while (true) {
        map.update();
        map.display();

        std::cin.get();
    }

    return 0;
}

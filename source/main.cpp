#include "../headers/allIncludes.hpp"

int main() {
    hideCursor();
    
    map.set();

    while (true) {
        map.update();
        map.display();

        std::cin.get();
        clearScreen();
    }

    return 0;
}
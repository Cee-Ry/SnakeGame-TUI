#include "../headers/allIncludes.hpp"

int main() {
    hideCursor();

    while (true) {
        map.set();

        std::cin.get();
        clearScreen();
    }

    return 0;
}
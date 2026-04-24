#include "../headers/food.hpp"
#include "../headers/map.hpp"

Food food;
randomPosition randY(1, map.height - 2);
randomPosition randX(2, map.width - 4);

int Food::fruitY() {
    return randY.position();
}
int Food::fruitX() {
    int evenNum {randX.position()};
    return (evenNum / 2) * 2;
}


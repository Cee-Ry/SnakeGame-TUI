#ifndef FOOD_HPP
#define FOOD_HPP

#include <string>
#include <random>

struct randomPosition {
    std::mt19937 rng;
    std::uniform_int_distribution<int> dist;

    randomPosition(int min, int max) 
        : rng(std::random_device()())
        , dist(min, max) {}

    int position() {
        return dist(rng);
    }
};

struct Food {
    int fruitY();
    int fruitX();

    int Y = fruitY();
    int X = fruitX();

    int score {0};
    bool isEaten {true};

    std::string fruit {"\033[33;43mF\033[0m"};
};

extern Food food;

#endif


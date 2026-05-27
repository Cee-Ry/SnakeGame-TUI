#pragma once

struct Snake {};

struct GameMap {
    int width {15};
    int height {4};

    void draw();
    void update();
};

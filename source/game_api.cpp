#include "../headers/game_api.hpp"
#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <algorithm>

void GameMap::reset() {
    s.body.clear();
    int startY = (LINES + top) / 2;
    int startX = COLS / 2;
    s.body.emplace_back(startY, startX);
    s.body.emplace_back(startY, startX - 1);
    s.body.emplace_back(startY, startX - 2);
    s.score = 0;
    dir = RIGHT;
    pause = false;
    gameOver = false;
    placeFood();
}

void GameMap::placeFood() {
    int minY = top + 1;
    int maxY = LINES - 2;
    int minX = border + 1;
    int maxX = COLS - border - 2;

    if (maxY < minY) {
        foodY = top + 1;
    } else {
        foodY = minY + std::rand() % (maxY - minY + 1);
    }

    if (maxX < minX) {
        foodX = border + 1;
    } else {
        foodX = minX + std::rand() % (maxX - minX + 1);
    }

    while (hitSelf(foodY, foodX)) {
        foodY = minY + std::rand() % (maxY - minY + 1);
        foodX = minX + std::rand() % (maxX - minX + 1);
    }
}

bool GameMap::hitWall(int y, int x) const {
    if (y <= top || y >= LINES - 1) {
        return true;
    }
    if (x <= border || x >= COLS - border) {
        return true;
    }
    return false;
}

bool GameMap::hitSelf(int y, int x) const {
    for (auto &segment : s.body) {
        if (segment.first == y && segment.second == x) {
            return true;
        }
    }
    return false;
}

void GameMap::drawBorders() const {
    attron(COLOR_PAIR(1));
    int bottom = LINES - 1;
    int right = COLS - border;

    for (int row = top; row <= bottom; ++row) {
        mvaddch(row, border, '#');
        mvaddch(row, right, '#');
    }

    for (int col = border; col <= right; ++col) {
        mvaddch(top, col, '#');
        mvaddch(bottom, col, '#');
    }
    attroff(COLOR_PAIR(1));
}

void GameMap::drawScore() const {
    mvprintw(0, 2, "Score: %d", s.score);
    mvprintw(1, 2, "Use arrow keys to move");
    mvprintw(2, 2, "Press ESC to pause");
}

void GameMap::draw() {
    drawBorders();
    attron(COLOR_PAIR(1));
    mvaddch(foodY, foodX, '*');
    attroff(COLOR_PAIR(1));

    attron(COLOR_PAIR(2));
    bool isHead = true;
    for (auto &segment : s.body) {
        mvaddch(segment.first, segment.second, isHead ? s.head : s.tail);
        isHead = false;
    }
    attroff(COLOR_PAIR(2));
    drawScore();
}

void GameMap::update() {
    if (dir == Stay) {
        return;
    }

    auto head = s.body.front();
    int nextY = head.first;
    int nextX = head.second;

    switch (dir) {
        case UP:
            nextY -= 1;
            break;
        case DOWN:
            nextY += 1;
            break;
        case LEFT:
            nextX -= 1;
            break;
        case RIGHT:
            nextX += 1;
            break;
        default:
            break;
    }

    if (hitWall(nextY, nextX) || hitSelf(nextY, nextX)) {
        gameOver = true;
        return;
    }

    s.body.emplace_front(nextY, nextX);

    if (nextY == foodY && nextX == foodX) {
        s.score += 10;
        placeFood();
    } else {
        s.body.pop_back();
    }
}

void GameMap::nav() {
    int key = getch();
    switch (key) {
        case KEY_UP:
            if (dir != DOWN) {
                dir = UP;
            }
            break;
        case KEY_DOWN:
            if (dir != UP) {
                dir = DOWN;
            }
            break;
        case KEY_LEFT:
            if (dir != RIGHT) {
                dir = LEFT;
            }
            break;
        case KEY_RIGHT:
            if (dir != LEFT) {
                dir = RIGHT;
            }
            break;
        case 27:
            pause = true;
            break;
        default:
            break;
    }
}

void GameMap::drawGameOver() const {
    const char *message1 = " GAME OVER ";
    const char *message2 = " Press Enter to return to menu ";
    int centerY = LINES / 2;
    int centerX = COLS / 2;

    mvprintw(centerY - 1, centerX - static_cast<int>(std::strlen(message1)) / 2, "%s", message1);
    mvprintw(centerY, centerX - 10, "Final score: %d", s.score);
    mvprintw(centerY + 1, centerX - static_cast<int>(std::strlen(message2)) / 2, "%s", message2);
}


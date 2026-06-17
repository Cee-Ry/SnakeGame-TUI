cmake_minimum_required(VERSION 3.10)
project(SnakeGame-TUI)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(snake
    source/main.cpp
    source/game_api.cpp
)

install(TARGETS snake
    DESTINATION $ENV{HOME}/.local/bin
)

find_package(Curses REQUIRED)

target_include_directories(snake PUBLIC
    "headers"
    ${CURSES_INCLUDE_DIR}
)

target_link_libraries(snake ${CURSES_LIBRARY})

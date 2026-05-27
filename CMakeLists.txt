cmake_minimum_required(VERSION 3.10)
project(SnakeGame-TUI)

add_executable(snake
    source/main.cpp
)

install(TARGETS snake
    DESTINATION $ENV{HOME}/.local/bin
)

find_package(Curses REQUIRED)

target_include_directories(snake PUBLIC
    "headers"
    ${CURSES_INCLUDE_DIR}
)

target_link_libraries(menedrix ${CURSES_LIBRARY})

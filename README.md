# SnakeGame-TUI

A sleek, terminal-based Snake game built in C++ with a minimalist text user interface. Enjoy fast-paced arcade action directly from your shell.

## Features

- **Classic Snake gameplay** with responsive controls
- **Terminal UI** for lightweight, distraction-free play
- **Easy to build** with standard C++ and ncurses-compatible libraries
- **Small, portable codebase** ideal for learning and customization

> Note: This project is still a work in progress. Some listed features and controls may not be fully implemented yet. CMakeList.txt is also useless(for now)

## Controls

- `W` / `↑` : Move up
- `S` / `↓` : Move down
- `A` / `←` : Move left
- `D` / `→` : Move right
- `Q` : Quit game

## Getting Started

1. Clone the repository:
   ```bash
   git clone https://github.com/Cee-Ry/SnakeGame-TUI.git
   cd SnakeGame-TUI/build
   ```

2. Build the game:
   ```bash
   cmake .. && make
   ```

3. Run it:
   ```bash
   ./snake
   ```

## Project Structure

- `header/` - game class declarations
- `source/` - implementation and program entry point
- `main` - compiled executable target

## Customize

Want to add new features like walls, scoreboards, or power-ups? Start by editing `header/game.hpp` and `source/game.cpp`.

## License

Open source and free to modify. Have fun!

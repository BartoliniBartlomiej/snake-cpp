# Terminal Snake

A terminal-based implementation of the classic Snake game written in C++17.

The project was created as a recruitment assignment and focuses on object-oriented design, unit testing and continuous development using GitHub.

## Features

* fixed 30x30 game board
* walls rendered outside the playable area
* snake movement controlled from the keyboard
* collision detection with walls
* self-collision detection
* fruit generation on unoccupied board positions
* snake growth after collecting fruit
* automatic fruit respawn
* terminal-based board rendering
* immediate keyboard input without pressing Enter
* automatic board refresh after every command
* unit tests using GoogleTest and GoogleMock
* continuous integration with GitHub Actions

## Controls

| Key     | Action                           |
| ------- | -------------------------------- |
| `SPACE` | Move forward by one field        |
| `L`     | Turn left and move by one field  |
| `R`     | Turn right and move by one field |
| `D`     | Display / refresh the board      |

Both uppercase and lowercase `L`, `R` and `D` are supported.

The game ends when the snake collides with a wall or with its own body.

## Requirements

* C++17 compatible compiler
* CMake 3.16 or newer
* Git
* macOS or Linux terminal

GoogleTest and GoogleMock are downloaded automatically by CMake using `FetchContent`.

The current terminal input implementation uses POSIX `termios`, therefore Windows is not currently supported.

## Build

Clone the repository:

```bash
git clone https://github.com/BartoliniBartlomiej/snake-cpp
cd snake-cpp
```

Configure the project:

```bash
cmake -S . -B build -DBUILD_TESTING=ON
```

Build:

```bash
cmake --build build
```

## Run

Start the game with:

```bash
./build/snake
```

## Tests

Build the project first:

```bash
cmake -S . -B build -DBUILD_TESTING=ON
cmake --build build
```

Run all tests:

```bash
ctest --test-dir build --output-on-failure
```

The project uses GoogleTest and GoogleMock, including mocked dependencies with `StrictMock` and `EXPECT_CALL`.

## Project Structure

```text
.
├── include/
│   ├── Board.hpp
│   ├── BoardRenderer.hpp
│   ├── Direction.hpp
│   ├── FruitGenerator.hpp
│   ├── Game.hpp
│   ├── GameCommand.hpp
│   ├── GameController.hpp
│   ├── InputParser.hpp
│   ├── Position.hpp
│   ├── RandomFruitGenerator.hpp
│   ├── Snake.hpp
│   └── TerminalInput.hpp
├── src/
│   ├── Board.cpp
│   ├── BoardRenderer.cpp
│   ├── Direction.cpp
│   ├── FruitGenerator.cpp
│   ├── Game.cpp
│   ├── GameController.cpp
│   ├── InputParser.cpp
│   ├── main.cpp
│   ├── Position.cpp
│   ├── RandomFruitGenerator.cpp
│   ├── Snake.cpp
│   └── TerminalInput.cpp
├── tests/
├── .github/workflows/
└── CMakeLists.txt
```

## Architecture

The project is divided into small classes with separate responsibilities:

* `Position` represents coordinates on the board.
* `Direction` defines snake movement directions and turning logic.
* `Snake` manages the snake body, movement, growth and self-collision detection.
* `Board` defines the playable 30x30 area.
* `FruitGenerator` provides an abstraction for fruit generation.
* `RandomFruitGenerator` generates fruit on free board positions.
* `Game` contains the main game state and game rules.
* `BoardRenderer` converts the current game state into terminal output.
* `InputParser` converts keyboard input into game commands.
* `GameController` executes commands on the game.
* `TerminalInput` provides immediate keyboard input in the terminal.

This separation keeps the game logic independent from terminal input and rendering, which also makes the individual components easier to unit test.

## Continuous Integration

GitHub Actions automatically:

1. configures the project with CMake,
2. builds the application,
3. runs the unit test suite.

The workflow is executed for pull requests targeting `main` and for pushes to `main`.


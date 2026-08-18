#pragma once

#include "Board.hpp"
#include "Snake.hpp"

class Game {
public:
    Game(Position initialSnakePosition, Direction initialDirection);

    void moveForward();

    bool isGameOver() const;

private:
    Board board_;
    Snake snake_;
    bool gameOver_{false};
};
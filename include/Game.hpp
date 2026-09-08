#pragma once

#include "Board.hpp"
#include "Snake.hpp"
#include "FruitGenerator.hpp"

class Game {
public:
    Game(Position initialSnakePosition, Direction initialDirection, FruitGenerator& fruitGenerator);

    void moveForward();
    void moveLeft();
    void moveRight();

    const Snake& snake() const;
    const Position& fruit() const;

    bool isGameOver() const;

private:
    Board board_;
    Snake snake_;
    Position fruit_;
    FruitGenerator& fruitGenerator_;
    
    bool gameOver_{false};

    void updateGameState();
};
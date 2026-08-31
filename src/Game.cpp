#include "Game.hpp"

Game::Game(Position initialSnakePosition,
           Direction initialDirection,
           Position initialFruitPosition,
           FruitGenerator& fruitGenerator)
    : snake_{initialSnakePosition, initialDirection},
      fruit_{initialFruitPosition},
      fruitGenerator_{fruitGenerator} {
}

void Game::updateGameState() {
    if (!board_.isInside(snake_.head())) {
        gameOver_ = true;
    }

    if (snake_.head() == fruit_) {
        snake_.grow();
        fruit_ = fruitGenerator_.generate(board_, snake_);
    }
}

bool Game::isGameOver() const {
    return gameOver_;
}

void Game::moveForward() {
    snake_.moveForward();
    updateGameState();
}

void Game::moveLeft() {
    snake_.moveLeft();
    updateGameState();
}

void Game::moveRight() {
    snake_.moveRight();
    updateGameState();
}

const Snake& Game::snake() const {
    return snake_;
}

const Position& Game::fruit() const {
    return fruit_;
}
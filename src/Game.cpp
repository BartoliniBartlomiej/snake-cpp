#include "Game.hpp"

Game::Game(Position initialSnakePosition, Direction initialDirection)
    : snake_{initialSnakePosition, initialDirection} {
}

void Game::updateGameState() {
    if (!board_.isInside(snake_.head())) {
        gameOver_ = true;
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
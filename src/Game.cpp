#include "Game.hpp"

Game::Game(Position initialSnakePosition, Direction initialDirection)
    : snake_{initialSnakePosition, initialDirection} {
}

bool Game::isGameOver() const {
    return gameOver_;
}

void Game::moveForward() {
    snake_.moveForward();

    if (!board_.isInside(snake_.head())) {
        gameOver_ = true;
    }
}
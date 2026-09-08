#include "GameController.hpp"

void GameController::execute(Game& game, GameCommand command) const {
    switch (command) {
        case GameCommand::MoveForward:
            game.moveForward();
            break;

        case GameCommand::TurnLeft:
            game.moveLeft();
            break;

        case GameCommand::TurnRight:
            game.moveRight();
            break;

        case GameCommand::Display:
        case GameCommand::Unknown:
            break;
    }
}
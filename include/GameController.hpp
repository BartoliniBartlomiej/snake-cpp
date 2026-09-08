#pragma once

#include "Game.hpp"
#include "GameCommand.hpp"

class GameController {
public:
    void execute(Game& game, GameCommand command) const;
};
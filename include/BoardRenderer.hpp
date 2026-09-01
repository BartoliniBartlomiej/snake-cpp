#pragma once

#include "Game.hpp"

#include <string>

class BoardRenderer {
public:
    std::string render(const Game& game) const;
};
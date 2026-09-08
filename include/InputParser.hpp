#pragma once

#include "GameCommand.hpp"

class InputParser {
public:
    GameCommand parse(char input) const;
};
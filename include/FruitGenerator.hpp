#pragma once

#include "Board.hpp"
#include "Position.hpp"
#include "Snake.hpp"

class FruitGenerator {
public:
    virtual ~FruitGenerator();

    virtual Position generate(const Board& board, const Snake& snake) = 0;
};
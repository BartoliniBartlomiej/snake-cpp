#pragma once

#include "Position.hpp"

class Board {
public:
    static constexpr int WIDTH = 30;
    static constexpr int HEIGHT = 30;

    bool isInside(const Position& position) const;
};
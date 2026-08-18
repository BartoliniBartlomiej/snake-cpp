#pragma once

#include "Direction.hpp"
#include "Position.hpp"

#include <cstddef>
#include <deque>
#include <optional>

class Snake {
public:
    Snake(Position initialPosition, Direction initialDirection);

    void moveForward();
    void moveLeft();
    void moveRight();

    const Position& head() const;
    Direction direction() const;
    std::size_t length() const;
    const std::deque<Position>& body() const;

    bool hasSelfCollision() const;

    void grow();

private:
    Position nextHeadPosition() const;
    void advance();

    std::deque<Position> body_;
    Direction direction_;
    std::optional<Position> lastTailPosition_;
};
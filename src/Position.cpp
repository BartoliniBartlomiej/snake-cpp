#include "Position.hpp"

Position::Position(int x, int y)
    : x_{x},
      y_{y}
      
{}

int Position::x() const {
    return x_;
}

int Position::y() const {
    return y_;
}

bool Position::operator==(const Position& other) const {
    return x_ == other.x_ && y_ == other.y_;
}

bool Position::operator!=(const Position& other) const {
    return !(*this == other);
}
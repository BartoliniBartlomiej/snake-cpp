#include "Board.hpp"

bool Board::isInside(const Position& position) const {
    return  position.x() >= 0 &&
            position.x() < WIDTH &&
            position.y() >= 0 &&
            position.y() < HEIGHT;
}
#include "Direction.hpp"

#include <stdexcept>

Direction turnLeft(Direction direction) {
    switch (direction) {
        case Direction::Up:
            return Direction::Left;
        case Direction::Left:
            return Direction::Down;
        case Direction::Down:
            return Direction::Right;
        case Direction::Right:
            return Direction::Up;
    }

    throw std::invalid_argument{"Invalid direction"};
}

Direction turnRight(Direction direction) {
    switch (direction) {
        case Direction::Up:
            return Direction::Right;
        case Direction::Right:
            return Direction::Down;
        case Direction::Down:
            return Direction::Left;
        case Direction::Left:
            return Direction::Up;
    }

    throw std::invalid_argument{"Invalid direction"};
}
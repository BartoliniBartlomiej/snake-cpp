#include "Snake.hpp"

#include <stdexcept>

Snake::Snake(Position initialPosition, Direction initialDirection)
    : body_{initialPosition},
      direction_{initialDirection} {
}

void Snake::moveForward() {
    advance();
}

void Snake::moveLeft() {
    direction_ = turnLeft(direction_);
    advance();
}

void Snake::moveRight() {
    direction_ = turnRight(direction_);
    advance();
}

const Position& Snake::head() const {
    return body_.front();
}

Direction Snake::direction() const {
    return direction_;
}

std::size_t Snake::length() const {
    return body_.size();
}

const std::deque<Position>& Snake::body() const {
    return body_;
}

Position Snake::nextHeadPosition() const {
    const Position& currentHead = head();

    switch (direction_) {
        case Direction::Up:
            return {currentHead.x(), currentHead.y() - 1};
        case Direction::Right:
            return {currentHead.x() + 1, currentHead.y()};
        case Direction::Down:
            return {currentHead.x(), currentHead.y() + 1};
        case Direction::Left:
            return {currentHead.x() - 1, currentHead.y()};
    }

    throw std::invalid_argument{"Invalid direction"};
}

void Snake::advance() {
    lastTailPosition_ = body_.back();

    body_.push_front(nextHeadPosition());
    body_.pop_back();
}

void Snake::grow() {
    if (!lastTailPosition_.has_value()) {
        throw std::logic_error{"Snake cannot grow before moving"};
    }

    body_.push_back(*lastTailPosition_);
    lastTailPosition_.reset();
}
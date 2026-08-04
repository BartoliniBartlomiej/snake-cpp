#pragma once

enum class Direction {
    Up,
    Right,
    Down,
    Left
};

Direction turnLeft(Direction direction);
Direction turnRight(Direction direction);
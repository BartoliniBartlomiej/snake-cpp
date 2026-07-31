#pragma once

class Position {
public:
    Position(int x, int y);

    int x() const;
    int y() const;

    bool operator==(const Position& other) const;
    bool operator!=(const Position& other) const;

private:
    int x_;
    int y_;
};
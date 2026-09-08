#include "InputParser.hpp"

GameCommand InputParser::parse(char input) const {
    switch (input) {
        case ' ':
            return GameCommand::MoveForward;

        case 'l':
        case 'L':
            return GameCommand::TurnLeft;

        case 'r':
        case 'R':
            return GameCommand::TurnRight;

        case 'd':
        case 'D':
            return GameCommand::Display;

        default:
            return GameCommand::Unknown;
    }
}
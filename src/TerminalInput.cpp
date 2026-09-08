#include "TerminalInput.hpp"

#include <iostream>
#include <unistd.h>

TerminalInput::TerminalInput() {
    tcgetattr(STDIN_FILENO, &originalSettings_);

    termios rawSettings = originalSettings_;

    rawSettings.c_lflag &= static_cast<tcflag_t>(~(ICANON | ECHO));

    tcsetattr(STDIN_FILENO, TCSANOW, &rawSettings);
}

TerminalInput::~TerminalInput() {
    tcsetattr(STDIN_FILENO, TCSANOW, &originalSettings_);
}

char TerminalInput::readKey() const {
    char input;
    std::cin.get(input);
    return input;
}
#include "TerminalInput.hpp"

#include <iostream>
#include <unistd.h>

TerminalInput::TerminalInput() {
    if (tcgetattr(STDIN_FILENO, &originalSettings_) != 0) {
        return;
    }

    termios rawSettings = originalSettings_;
    rawSettings.c_lflag &= static_cast<tcflag_t>(~(ICANON | ECHO));

    if (tcsetattr(STDIN_FILENO, TCSANOW, &rawSettings) == 0) {
        terminalConfigured_ = true;
    }
}

TerminalInput::~TerminalInput() {
    if (terminalConfigured_) {
        tcsetattr(STDIN_FILENO, TCSANOW, &originalSettings_);
    }
}

char TerminalInput::readKey() const {
    char input{};
    std::cin.get(input);
    return input;
}
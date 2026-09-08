#pragma once

#include <termios.h>

class TerminalInput {
public:
    TerminalInput();
    ~TerminalInput();

    char readKey() const;

private:
    termios originalSettings_{};
    bool terminalConfigured_{false};
};
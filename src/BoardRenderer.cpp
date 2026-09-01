#include "BoardRenderer.hpp"

#include <algorithm>
#include <sstream>

std::string BoardRenderer::render(const Game& game) const {
    std::ostringstream output;

    output << '+'
           << std::string(Board::WIDTH, '-')
           << "+\n";

    for (int y = 0; y < Board::HEIGHT; ++y) {
        output << '|';

        for (int x = 0; x < Board::WIDTH; ++x) {
            const Position position{x, y};

            const auto& body = game.snake().body();

            const bool snakeOccupiesPosition =
                std::find(body.begin(), body.end(), position) != body.end();

            if (snakeOccupiesPosition) {
                output << 'S';
            } else if (game.fruit() == position) {
                output << 'F';
            } else {
                output << ' ';
            }
        }

        output << "|\n";
    }

    output << '+'
           << std::string(Board::WIDTH, '-')
           << '+';

    return output.str();
}
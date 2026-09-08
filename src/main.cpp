#include "BoardRenderer.hpp"
#include "Game.hpp"
#include "GameController.hpp"
#include "InputParser.hpp"
#include "RandomFruitGenerator.hpp"
#include "TerminalInput.hpp"

#include <iostream>

void clearScreen() {
    std::cout << "\033[2J\033[H";
}

void displayGame(const Game& game, const BoardRenderer& renderer) {
    clearScreen();

    std::cout << renderer.render(game) << "\n\n";
    std::cout << "SPACE = forward | L = left | R = right | D = display\n";
}

int main() {
    RandomFruitGenerator fruitGenerator;

    Game game{
        {15, 15},
        Direction::Right,
        fruitGenerator
    };

    const BoardRenderer renderer;
    const InputParser inputParser;
    const GameController controller;
    const TerminalInput terminalInput;

    displayGame(game, renderer);

    while (!game.isGameOver()) {
        const char input = terminalInput.readKey();

        const GameCommand command = inputParser.parse(input);

        if (command != GameCommand::Display) {
            controller.execute(game, command);
        }

        displayGame(game, renderer);
    }

    clearScreen();
    std::cout << renderer.render(game) << "\n\n";
    std::cout << "Game over!\n";

    return 0;
}
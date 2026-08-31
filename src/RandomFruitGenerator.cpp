#include "RandomFruitGenerator.hpp"

#include <algorithm>

RandomFruitGenerator::RandomFruitGenerator()
    : generator_{std::random_device{}()} {
}

Position RandomFruitGenerator::generate(const Board&, const Snake& snake) {
    std::uniform_int_distribution<int> xDistribution{0, Board::WIDTH - 1};
    std::uniform_int_distribution<int> yDistribution{0, Board::HEIGHT - 1};

    while (true) {
        Position position{
            xDistribution(generator_),
            yDistribution(generator_)
        };

        const auto& body = snake.body();

        const bool occupied = std::find(
            body.begin(),
            body.end(),
            position
        ) != body.end();

        if (!occupied) {
            return position;
        }
    }
}
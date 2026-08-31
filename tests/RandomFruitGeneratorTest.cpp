#include "RandomFruitGenerator.hpp"

#include <gtest/gtest.h>

#include <algorithm>

TEST(RandomFruitGeneratorTest, GeneratesPositionInsideBoard) {
    const Board board;
    const Snake snake{{15, 15}, Direction::Right};
    RandomFruitGenerator generator;

    const Position position = generator.generate(board, snake);

    EXPECT_TRUE(board.isInside(position));
}

TEST(RandomFruitGeneratorTest, DoesNotGeneratePositionOccupiedBySnake) {
    const Board board;
    Snake snake{{15, 15}, Direction::Right};

    snake.moveForward();
    snake.grow();

    RandomFruitGenerator generator;

    const Position position = generator.generate(board, snake);

    const auto& body = snake.body();

    EXPECT_EQ(
        std::find(body.begin(), body.end(), position),
        body.end()
    );
}
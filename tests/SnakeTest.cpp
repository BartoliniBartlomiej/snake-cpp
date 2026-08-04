#include "Snake.hpp"

#include <gtest/gtest.h>

TEST(SnakeTest, StartsAtGivenPositionAndDirection) {
    const Snake snake{{15, 15}, Direction::Right};

    EXPECT_EQ(snake.head(), Position(15, 15));
    EXPECT_EQ(snake.direction(), Direction::Right);
    EXPECT_EQ(snake.length(), 1);
}

TEST(SnakeTest, MovesUpByOneField) {
    Snake snake{{15, 15}, Direction::Up};

    snake.moveForward();

    EXPECT_EQ(snake.head(), Position(15, 14));
}

TEST(SnakeTest, MovesRightByOneField) {
    Snake snake{{15, 15}, Direction::Right};

    snake.moveForward();

    EXPECT_EQ(snake.head(), Position(16, 15));
}

TEST(SnakeTest, MovesDownByOneField) {
    Snake snake{{15, 15}, Direction::Down};

    snake.moveForward();

    EXPECT_EQ(snake.head(), Position(15, 16));
}

TEST(SnakeTest, MovesLeftByOneField) {
    Snake snake{{15, 15}, Direction::Left};

    snake.moveForward();

    EXPECT_EQ(snake.head(), Position(14, 15));
}

TEST(SnakeTest, TurnsLeftAndMovesByOneField) {
    Snake snake{{15, 15}, Direction::Up};

    snake.moveLeft();

    EXPECT_EQ(snake.direction(), Direction::Left);
    EXPECT_EQ(snake.head(), Position(14, 15));
}

TEST(SnakeTest, TurnsRightAndMovesByOneField) {
    Snake snake{{15, 15}, Direction::Up};

    snake.moveRight();

    EXPECT_EQ(snake.direction(), Direction::Right);
    EXPECT_EQ(snake.head(), Position(16, 15));
}
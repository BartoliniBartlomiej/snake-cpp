#include "Game.hpp"

#include <gtest/gtest.h>

TEST(GameTest, IsNotOverAtStart) {
    const Game game{{15, 15}, Direction::Right};

    EXPECT_FALSE(game.isGameOver());
}

TEST(GameTest, ContinuesWhenSnakeMovesInsideBoard) {
    Game game{{15, 15}, Direction::Right};

    game.moveForward();

    EXPECT_FALSE(game.isGameOver());
}

TEST(GameTest, EndsWhenSnakeMovesOutsideBoard) {
    Game game{{29, 15}, Direction::Right};

    game.moveForward();

    EXPECT_TRUE(game.isGameOver());
}

TEST(GameTest, EndsWhenSnakeMovesOutsideLeftBoundary) {
    Game game{{0, 15}, Direction::Left};

    game.moveForward();

    EXPECT_TRUE(game.isGameOver());
}

TEST(GameTest, EndsWhenSnakeMovesOutsideTopBoundary) {
    Game game{{15, 0}, Direction::Up};

    game.moveForward();

    EXPECT_TRUE(game.isGameOver());
}

TEST(GameTest, EndsWhenSnakeMovesOutsideBottomBoundary) {
    Game game{{15, 29}, Direction::Down};

    game.moveForward();

    EXPECT_TRUE(game.isGameOver());
}

TEST(GameTest, MovesSnakeLeft) {
    Game game{{15, 15}, Direction::Up};

    game.moveLeft();

    EXPECT_EQ(game.snake().direction(), Direction::Left);
    EXPECT_EQ(game.snake().head(), Position(14, 15));
}

TEST(GameTest, MovesSnakeRight) {
    Game game{{15, 15}, Direction::Up};

    game.moveRight();

    EXPECT_EQ(game.snake().direction(), Direction::Right);
    EXPECT_EQ(game.snake().head(), Position(16, 15));
}

TEST(GameTest, EndsWhenSnakeTurnsIntoWall) {
    Game game{{0, 15}, Direction::Up};

    game.moveLeft();

    EXPECT_TRUE(game.isGameOver());
}
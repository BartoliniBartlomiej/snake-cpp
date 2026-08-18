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
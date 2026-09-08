#include "GameController.hpp"
#include "FruitGenerator.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

class MockFruitGenerator : public FruitGenerator {
public:
    MOCK_METHOD(Position,
                generate,
                (const Board& board, const Snake& snake),
                (override));
};

class GameControllerTest : public testing::Test {
protected:
    testing::StrictMock<MockFruitGenerator> fruitGenerator;
    GameController controller;
};

TEST_F(GameControllerTest, MovesGameForward) {
    Game game{
        {15, 15},
        Direction::Right,
        {5, 5},
        fruitGenerator
    };

    controller.execute(game, GameCommand::MoveForward);

    EXPECT_EQ(game.snake().head(), Position(16, 15));
}

TEST_F(GameControllerTest, TurnsGameLeft) {
    Game game{
        {15, 15},
        Direction::Up,
        {5, 5},
        fruitGenerator
    };

    controller.execute(game, GameCommand::TurnLeft);

    EXPECT_EQ(game.snake().direction(), Direction::Left);
    EXPECT_EQ(game.snake().head(), Position(14, 15));
}

TEST_F(GameControllerTest, TurnsGameRight) {
    Game game{
        {15, 15},
        Direction::Up,
        {5, 5},
        fruitGenerator
    };

    controller.execute(game, GameCommand::TurnRight);

    EXPECT_EQ(game.snake().direction(), Direction::Right);
    EXPECT_EQ(game.snake().head(), Position(16, 15));
}

TEST_F(GameControllerTest, DoesNotMoveGameForDisplayCommand) {
    Game game{
        {15, 15},
        Direction::Right,
        {5, 5},
        fruitGenerator
    };

    controller.execute(game, GameCommand::Display);

    EXPECT_EQ(game.snake().head(), Position(15, 15));
}

TEST_F(GameControllerTest, DoesNotMoveGameForUnknownCommand) {
    Game game{
        {15, 15},
        Direction::Right,
        {5, 5},
        fruitGenerator
    };

    controller.execute(game, GameCommand::Unknown);

    EXPECT_EQ(game.snake().head(), Position(15, 15));
}
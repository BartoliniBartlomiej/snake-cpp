#include "Game.hpp"
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

class GameTest : public testing::Test {
protected:
    testing::StrictMock<MockFruitGenerator> fruitGenerator;
};

TEST_F(GameTest, IsNotOverAtStart) {
    const Game game{{15, 15}, Direction::Right, {5, 5}, fruitGenerator};

    EXPECT_FALSE(game.isGameOver());
}

TEST_F(GameTest, ContinuesWhenSnakeMovesInsideBoard) {
    Game game{{15, 15}, Direction::Right, {5, 5}, fruitGenerator};

    game.moveForward();

    EXPECT_FALSE(game.isGameOver());
}

TEST_F(GameTest, EndsWhenSnakeMovesOutsideBoard) {
    Game game{{29, 15}, Direction::Right, {5, 5}, fruitGenerator};

    game.moveForward();

    EXPECT_TRUE(game.isGameOver());
}

TEST_F(GameTest, EndsWhenSnakeMovesOutsideLeftBoundary) {
    Game game{{0, 15}, Direction::Left, {5, 5}, fruitGenerator};

    game.moveForward();

    EXPECT_TRUE(game.isGameOver());
}

TEST_F(GameTest, EndsWhenSnakeMovesOutsideTopBoundary) {
    Game game{{15, 0}, Direction::Up, {5, 5}, fruitGenerator};

    game.moveForward();

    EXPECT_TRUE(game.isGameOver());
}

TEST_F(GameTest, EndsWhenSnakeMovesOutsideBottomBoundary) {
    Game game{{15, 29}, Direction::Down, {5, 5}, fruitGenerator};

    game.moveForward();

    EXPECT_TRUE(game.isGameOver());
}

TEST_F(GameTest, MovesSnakeLeft) {
    Game game{{15, 15}, Direction::Up, {5, 5}, fruitGenerator};

    game.moveLeft();

    EXPECT_EQ(game.snake().direction(), Direction::Left);
    EXPECT_EQ(game.snake().head(), Position(14, 15));
}

TEST_F(GameTest, MovesSnakeRight) {
    Game game{{15, 15}, Direction::Up, {5, 5}, fruitGenerator};

    game.moveRight();

    EXPECT_EQ(game.snake().direction(), Direction::Right);
    EXPECT_EQ(game.snake().head(), Position(16, 15));
}

TEST_F(GameTest, EndsWhenSnakeTurnsIntoWall) {
    Game game{{0, 15}, Direction::Up, {5, 5}, fruitGenerator};

    game.moveLeft();

    EXPECT_TRUE(game.isGameOver());
}

TEST_F(GameTest, StartsWithFruitAtGivenPosition) {
    const Game game{{15, 15}, Direction::Right, {20, 10}, fruitGenerator};

    EXPECT_EQ(game.fruit(), Position(20, 10));
}

TEST_F(GameTest, SnakeGrowsWhenItMovesOntoFruit) {
    Game game{
        {15, 15},
        Direction::Right,
        {16, 15},
        fruitGenerator
    };

    EXPECT_CALL(fruitGenerator, generate(testing::_, testing::_))
        .WillOnce(testing::Return(Position{20, 20}));

    game.moveForward();

    EXPECT_EQ(game.snake().length(), 2);
}

TEST_F(GameTest, GeneratesNewFruitAfterSnakeEatsFruit) {
    Game game{
        {15, 15},
        Direction::Right,
        {16, 15},
        fruitGenerator
    };

    EXPECT_CALL(fruitGenerator, generate(testing::_, testing::_))
        .WillOnce(testing::Return(Position{20, 20}));

    game.moveForward();

    EXPECT_EQ(game.fruit(), Position(20, 20));
}

TEST_F(GameTest, EndsWhenSnakeCollidesWithItself) {
    Game game{
        {15, 15},
        Direction::Right,
        {16, 15},
        fruitGenerator
    };

    EXPECT_CALL(fruitGenerator, generate(testing::_, testing::_))
        .WillOnce(testing::Return(Position{17, 15}))
        .WillOnce(testing::Return(Position{18, 15}))
        .WillOnce(testing::Return(Position{18, 16}))
        .WillOnce(testing::Return(Position{17, 16}))
        .WillOnce(testing::Return(Position{16, 16}));

    game.moveForward();
    game.moveForward();
    game.moveForward();

    game.moveRight();
    game.moveRight();
    game.moveRight();

    EXPECT_TRUE(game.isGameOver());
}
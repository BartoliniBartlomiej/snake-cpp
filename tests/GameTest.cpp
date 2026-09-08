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

    Game createGame(Position snakePosition,
                    Direction direction,
                    Position fruitPosition) {
        EXPECT_CALL(fruitGenerator, generate(testing::_, testing::_))
            .WillOnce(testing::Return(fruitPosition));

        return Game{
            snakePosition,
            direction,
            fruitGenerator
        };
    }
};

TEST_F(GameTest, IsNotOverAtStart) {
    const Game game = createGame(
        {15, 15},
        Direction::Right,
        {5, 5}
    );

    EXPECT_FALSE(game.isGameOver());
}

TEST_F(GameTest, ContinuesWhenSnakeMovesInsideBoard) {
    Game game = createGame(
        {15, 15},
        Direction::Right,
        {5, 5}
    );

    game.moveForward();

    EXPECT_FALSE(game.isGameOver());
}

TEST_F(GameTest, EndsWhenSnakeMovesOutsideBoard) {
    Game game = createGame(
        {29, 15},
        Direction::Right,
        {5, 5}
    );

    game.moveForward();

    EXPECT_TRUE(game.isGameOver());
}

TEST_F(GameTest, EndsWhenSnakeMovesOutsideLeftBoundary) {
    Game game = createGame(
        {0, 15},
        Direction::Left,
        {5, 5}
    );

    game.moveForward();

    EXPECT_TRUE(game.isGameOver());
}

TEST_F(GameTest, EndsWhenSnakeMovesOutsideTopBoundary) {
    Game game = createGame(
        {15, 0},
        Direction::Up,
        {5, 5}
    );

    game.moveForward();

    EXPECT_TRUE(game.isGameOver());
}

TEST_F(GameTest, EndsWhenSnakeMovesOutsideBottomBoundary) {
    Game game = createGame(
        {15, 29},
        Direction::Down,
        {5, 5}
    );

    game.moveForward();

    EXPECT_TRUE(game.isGameOver());
}

TEST_F(GameTest, MovesSnakeLeft) {
    Game game = createGame(
        {15, 15},
        Direction::Up,
        {5, 5}
    );

    game.moveLeft();

    EXPECT_EQ(game.snake().direction(), Direction::Left);
    EXPECT_EQ(game.snake().head(), Position(14, 15));
}

TEST_F(GameTest, MovesSnakeRight) {
    Game game = createGame(
        {15, 15},
        Direction::Up,
        {5, 5}
    );

    game.moveRight();

    EXPECT_EQ(game.snake().direction(), Direction::Right);
    EXPECT_EQ(game.snake().head(), Position(16, 15));
}

TEST_F(GameTest, EndsWhenSnakeTurnsIntoWall) {
    Game game = createGame(
        {0, 15},
        Direction::Up,
        {5, 5}
    );

    game.moveLeft();

    EXPECT_TRUE(game.isGameOver());
}

TEST_F(GameTest, StartsWithGeneratedFruit) {
    const Game game = createGame(
        {15, 15},
        Direction::Right,
        {20, 10}
    );

    EXPECT_EQ(game.fruit(), Position(20, 10));
}

TEST_F(GameTest, SnakeGrowsWhenItMovesOntoFruit) {
    Game game = createGame(
        {15, 15},
        Direction::Right,
        {16, 15}
    );

    EXPECT_CALL(fruitGenerator, generate(testing::_, testing::_))
        .WillOnce(testing::Return(Position{20, 20}));

    game.moveForward();

    EXPECT_EQ(game.snake().length(), 2);
}

TEST_F(GameTest, GeneratesNewFruitAfterSnakeEatsFruit) {
    Game game = createGame(
        {15, 15},
        Direction::Right,
        {16, 15}
    );

    EXPECT_CALL(fruitGenerator, generate(testing::_, testing::_))
        .WillOnce(testing::Return(Position{20, 20}));

    game.moveForward();

    EXPECT_EQ(game.fruit(), Position(20, 20));
}

TEST_F(GameTest, EndsWhenSnakeCollidesWithItself) {
    Game game = createGame(
        {15, 15},
        Direction::Right,
        {16, 15}
    );

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
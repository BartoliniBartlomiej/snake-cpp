#include "BoardRenderer.hpp"
#include "FruitGenerator.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <algorithm>
#include <sstream>

class MockFruitGenerator : public FruitGenerator {
public:
    MOCK_METHOD(Position,
                generate,
                (const Board& board, const Snake& snake),
                (override));
};

TEST(BoardRendererTest, RendersSnakeAndFruit) {
    testing::StrictMock<MockFruitGenerator> fruitGenerator;

    const Game game{
        {15, 15},
        Direction::Right,
        {20, 10},
        fruitGenerator
    };

    const BoardRenderer renderer;

    const std::string output = renderer.render(game);

    EXPECT_NE(output.find('S'), std::string::npos);
    EXPECT_NE(output.find('F'), std::string::npos);
}

TEST(BoardRendererTest, RendersBoardWithCorrectDimensions) {
    testing::StrictMock<MockFruitGenerator> fruitGenerator;

    const Game game{
        {15, 15},
        Direction::Right,
        {20, 10},
        fruitGenerator
    };

    const BoardRenderer renderer;
    const std::string output = renderer.render(game);

    const int lineCount =
        static_cast<int>(std::count(output.begin(), output.end(), '\n')) + 1;

    EXPECT_EQ(lineCount, Board::HEIGHT + 2);
}

TEST(BoardRendererTest, RendersEveryLineWithCorrectWidth) {
    testing::StrictMock<MockFruitGenerator> fruitGenerator;

    const Game game{
        {15, 15},
        Direction::Right,
        {20, 10},
        fruitGenerator
    };

    const BoardRenderer renderer;
    const std::string output = renderer.render(game);

    std::istringstream stream{output};
    std::string line;

    while (std::getline(stream, line)) {
        EXPECT_EQ(line.size(), Board::WIDTH + 2);
    }
}

TEST(BoardRendererTest, RendersObjectsAtCorrectPositions) {
    testing::StrictMock<MockFruitGenerator> fruitGenerator;

    const Game game{
        {2, 3},
        Direction::Right,
        {5, 7},
        fruitGenerator
    };

    const BoardRenderer renderer;
    const std::string output = renderer.render(game);

    std::istringstream stream{output};
    std::string line;

    for (int y = -1; std::getline(stream, line); ++y) {
        if (y == 3) {
            EXPECT_EQ(line[3], 'S');
        }

        if (y == 7) {
            EXPECT_EQ(line[6], 'F');
        }
    }
}

TEST(BoardRendererTest, RendersEntireSnakeBody) {
    testing::StrictMock<MockFruitGenerator> fruitGenerator;

    Game game{
        {15, 15},
        Direction::Right,
        {16, 15},
        fruitGenerator
    };

    EXPECT_CALL(fruitGenerator, generate(testing::_, testing::_))
        .WillOnce(testing::Return(Position{20, 20}));

    game.moveForward();

    const BoardRenderer renderer;
    const std::string output = renderer.render(game);

    const auto snakeFieldCount =
        std::count(output.begin(), output.end(), 'S');

    EXPECT_EQ(snakeFieldCount, 2);
}
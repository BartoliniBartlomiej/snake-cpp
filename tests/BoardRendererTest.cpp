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

    EXPECT_CALL(fruitGenerator, generate(testing::_, testing::_))
        .WillOnce(testing::Return(Position{20, 20}));

    Game game{
        {15, 15},
        Direction::Right,
        fruitGenerator
    };

    const BoardRenderer renderer;
    const std::string output = renderer.render(game);

    EXPECT_NE(output.find('S'), std::string::npos);
    EXPECT_NE(output.find('F'), std::string::npos);
}

TEST(BoardRendererTest, RendersBoardWithCorrectDimensions) {
    testing::StrictMock<MockFruitGenerator> fruitGenerator;

    EXPECT_CALL(fruitGenerator, generate(testing::_, testing::_))
        .WillOnce(testing::Return(Position{20, 20}));

    Game game{
        {15, 15},
        Direction::Right,
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

    EXPECT_CALL(fruitGenerator, generate(testing::_, testing::_))
        .WillOnce(testing::Return(Position{20, 20}));

    Game game{
        {15, 15},
        Direction::Right,
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

    EXPECT_CALL(fruitGenerator, generate(testing::_, testing::_))
        .WillOnce(testing::Return(Position{20, 20}));

    Game game{
        {15, 15},
        Direction::Right,
        fruitGenerator
    };

    const BoardRenderer renderer;
    const std::string output = renderer.render(game);

    std::istringstream stream{output};
    std::string line;

    int lineIndex = 0;

    while (std::getline(stream, line)) {
        if (lineIndex == 16) {
            EXPECT_EQ(line[16], 'S');
        }

        if (lineIndex == 21) {
            EXPECT_EQ(line[21], 'F');
        }

        ++lineIndex;
    }
}

TEST(BoardRendererTest, RendersEntireSnakeBody) {
    testing::StrictMock<MockFruitGenerator> fruitGenerator;

    EXPECT_CALL(fruitGenerator, generate(testing::_, testing::_))
        .WillOnce(testing::Return(Position{16, 15}));

    Game game{
        {15, 15},
        Direction::Right,
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
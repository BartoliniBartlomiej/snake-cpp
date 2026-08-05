#include "Board.hpp"

#include <gtest/gtest.h>

TEST(BoardTest, PositionsInsideBoardAreValid) {
    const Board board;

    EXPECT_TRUE(board.isInside({0, 0}));
    EXPECT_TRUE(board.isInside({29, 0}));
    EXPECT_TRUE(board.isInside({0, 29}));
    EXPECT_TRUE(board.isInside({29, 29}));
    EXPECT_TRUE(board.isInside({15, 15}));
}

TEST(BoardTest, PositionsOutsideHorizontalBoundsAreInvalid) {
    const Board board;

    EXPECT_FALSE(board.isInside({-1, 15}));
    EXPECT_FALSE(board.isInside({30, 15}));
}

TEST(BoardTest, PositionsOutsideVerticalBoundsAreInvalid) {
    const Board board;

    EXPECT_FALSE(board.isInside({15, -1}));
    EXPECT_FALSE(board.isInside({15, 30}));
}
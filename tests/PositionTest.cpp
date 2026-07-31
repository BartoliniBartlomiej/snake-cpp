#include "Position.hpp"

#include <gtest/gtest.h>

TEST(PositionTest, StoresCoordinates) {
    const Position position{5, 12};

    EXPECT_EQ(position.x(), 5);
    EXPECT_EQ(position.y(), 12);
}

TEST(PositionTest, PositionsWithSameCoordinatesAreEqual) {
    const Position first{5, 12};
    const Position second{5, 12};

    EXPECT_EQ(first, second);
}

TEST(PositionTest, PositionsWithDifferentCoordinatesAreNotEqual) {
    const Position first{5, 12};
    const Position second{6, 12};

    EXPECT_NE(first, second);
}
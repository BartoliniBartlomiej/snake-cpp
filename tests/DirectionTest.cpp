#include "Direction.hpp"

#include <gtest/gtest.h>

TEST(DirectionTest, TurnsLeftFromEveryDirection) {
    EXPECT_EQ(turnLeft(Direction::Up), Direction::Left);
    EXPECT_EQ(turnLeft(Direction::Left), Direction::Down);
    EXPECT_EQ(turnLeft(Direction::Down), Direction::Right);
    EXPECT_EQ(turnLeft(Direction::Right), Direction::Up);
}

TEST(DirectionTest, TurnsRightFromEveryDirection) {
    EXPECT_EQ(turnRight(Direction::Up), Direction::Right);
    EXPECT_EQ(turnRight(Direction::Right), Direction::Down);
    EXPECT_EQ(turnRight(Direction::Down), Direction::Left);
    EXPECT_EQ(turnRight(Direction::Left), Direction::Up);
}
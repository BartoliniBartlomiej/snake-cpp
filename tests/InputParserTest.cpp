#include "InputParser.hpp"

#include <gtest/gtest.h>

TEST(InputParserTest, ParsesSpaceAsMoveForward) {
    const InputParser parser;

    EXPECT_EQ(parser.parse(' '), GameCommand::MoveForward);
}

TEST(InputParserTest, ParsesLAsTurnLeft) {
    const InputParser parser;

    EXPECT_EQ(parser.parse('L'), GameCommand::TurnLeft);
    EXPECT_EQ(parser.parse('l'), GameCommand::TurnLeft);
}

TEST(InputParserTest, ParsesRAsTurnRight) {
    const InputParser parser;

    EXPECT_EQ(parser.parse('R'), GameCommand::TurnRight);
    EXPECT_EQ(parser.parse('r'), GameCommand::TurnRight);
}

TEST(InputParserTest, ParsesDAsDisplay) {
    const InputParser parser;

    EXPECT_EQ(parser.parse('D'), GameCommand::Display);
    EXPECT_EQ(parser.parse('d'), GameCommand::Display);
}

TEST(InputParserTest, ReturnsUnknownForUnsupportedInput) {
    const InputParser parser;

    EXPECT_EQ(parser.parse('x'), GameCommand::Unknown);
}
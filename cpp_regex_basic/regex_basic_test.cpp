/**
 * C++ regular expressions examples
 */

#include "gtest/gtest.h"
#include "regex_basic.h"

/*
 *  .   any character except newline
 *  ?   zero or 1 preceding character
 *  *   zero or more preceding character
 *  +   one or more preceding character
 *  []  any character inside the bracket
 *  [^] amy character not inside the bracket
 */

TEST(BasicRegexTest, Dot) {
    EXPECT_EQ(match("hel", "hel"), true);
    EXPECT_EQ(match("hell", "hel"), false);
    EXPECT_EQ(match("help", "hel"), false);

    EXPECT_EQ(match("helo", "hel."), true);
    EXPECT_EQ(match("hell", "hel."), true);
    EXPECT_EQ(match("help", "hel."), true);
    EXPECT_EQ(match("hello", "hel."), false);
}

TEST(BasicRegexTest, Question) {
    EXPECT_EQ(match("he", "hel?"), true);
    EXPECT_EQ(match("hel", "hel?"), true);
    EXPECT_EQ(match("hell", "hel?"), false);
    EXPECT_EQ(match("help", "hel?"), false);
}

TEST(BasicRegexTest, Asterisk) {
    EXPECT_EQ(match("he", "hel*"), true);
    EXPECT_EQ(match("hel", "hel*"), true);
    EXPECT_EQ(match("hell", "hel*"), true);
    EXPECT_EQ(match("helllllll", "hel*"), true);
    EXPECT_EQ(match("hello", "hel*"), false);
    EXPECT_EQ(match("helllllo", "hel*"), false);
}

TEST(BasicRegexTest, Plus) {
    EXPECT_EQ(match("he", "hel+"), false);
    EXPECT_EQ(match("hel", "hel+"), true);
    EXPECT_EQ(match("hell", "hel+"), true);
    EXPECT_EQ(match("hellllll", "hel+"), true);
    EXPECT_EQ(match("help", "hel+"), false);
    EXPECT_EQ(match("hellllllo", "hel+"), false);
}

TEST(BasicRegexTest, Brackets) {
    EXPECT_EQ(match("help", "hel[pol]"), true);
    EXPECT_EQ(match("hell", "hel[pol]"), true);
    EXPECT_EQ(match("helo", "hel[pol]"), true);
    EXPECT_EQ(match("heli", "hel[pol]"), false);
    EXPECT_EQ(match("hello", "hel[pol]"), false);
    EXPECT_EQ(match("helpol", "hel[pol]"), false);

    EXPECT_EQ(match("heli","hel[^pol]"), true);
    EXPECT_EQ(match("heln", "hel[^pol]"), true);
    EXPECT_EQ(match("help", "hel[^pol]"), false);
    EXPECT_EQ(match("helmet", "hel[^pol]"), false);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// Compile with:
//  g++ regex_basic.cpp -o regex_basic.o -c -std=c++11
//  g++ regex_basic_test.cpp regex_basic.o  -o regex_basic_test -std=c++11 -lgtest
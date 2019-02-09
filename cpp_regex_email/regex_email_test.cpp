/**
 * Match regular expression
 */

#include <regex>
#include <iostream>
#include "gtest/gtest.h"

/*
 *  The valid email we define as follows.
 *  1. It ends with .com
 *  2. It has domain like @gmail
 */
bool isValidEmail(std::string str) {
    std::regex e("(\\w+)@(\\w+)(\\.(\\w+))+");
    /**
     * (\\w+) - One or more group of alphanumeric characters
     * @ - single @ character
     * (\\.(\\w+))+ - one or more group of character starting with . followed by alpha numeric characters
     */
    return std::regex_match(str, e);
}

bool isValidEmailImproved(std::string str) {
    std::regex e("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    /**
     * Also consider if email contains . or underscore
     */
    return std::regex_match(str, e);
}

TEST(AnyDomain, Positive) {
    EXPECT_EQ(isValidEmail("cg011235@gmail.com"), true);
    EXPECT_EQ(isValidEmail("cg011235@hotmail.com"), true);
    EXPECT_EQ(isValidEmailImproved("chaitanya.g@gmail.com"), true);
}

TEST(AnyDomain, Negative) {
    EXPECT_EQ(isValidEmail("abcdefghijk"), false);
    EXPECT_EQ(isValidEmail("chaitanya.g@gmail.com"), false);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
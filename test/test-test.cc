#include "gtest/gtest.h"
#include "TestInclude.h"
#include <string>
using std::string;

const char *actualValTrue  = "hello gtest";
const char *actualValFalse = "hello world";
const char *expectVal      = "hello gtest";

TEST(StrCompare, CStrEqual) {
    EXPECT_STREQ(expectVal, actualValTrue);
}

TEST(StrCompare, CStrNotEqual) {
    EXPECT_STREQ(expectVal, actualValFalse);
}

TEST(TestInclude, ret0) {
    EXPECT_EQ(0, printSomething("something"));
}

TEST(NewSuite, bleh) {
    EXPECT_NE(1, 2);
}

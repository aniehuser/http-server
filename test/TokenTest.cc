#include "gtest/gtest.h"
#include "Token.h"
#include <string>
#include <sstream>

void ostream_test(const char* expected, enum Token token);

TEST(TokenTests, to_string) {
    // Run a few random equality test. Just to ensure macros are included correctly
    EXPECT_STREQ("EQUAL", to_string(Token::EQUAL).c_str());
    EXPECT_STREQ("CRLF", to_string(Token::CRLF).c_str());
    EXPECT_STREQ("ALPHA", to_string(Token::ALPHA).c_str());
    EXPECT_STREQ("GET", to_string(Token::GET).c_str());
}

TEST(TokenTests, ostream) {
    // Again just a few random equality tests, this time using a stringstream to represent std::cout
    ostream_test("DOLLAR", Token::DOLLAR);
    ostream_test("DIGIT", Token::DIGIT);
    ostream_test("LF", Token::LF);
} 

void ostream_test(const char* expected, enum Token token) {
    std::stringstream ss;
    ss << token;
    EXPECT_STREQ(expected, ss.str().c_str());
}

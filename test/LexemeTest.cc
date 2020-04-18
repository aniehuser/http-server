#include "gtest/gtest.h"

#include <string>
#include <sstream>

#include "Lexeme.h"

TEST(LexemeTests, constructor) {
    std::string str = "<";
    enum Token token = Token::GREATERTHAN;
    Lexeme lex = Lexeme(token, str);
    EXPECT_STREQ(str.c_str(), lex.text.c_str());
    EXPECT_EQ(token, lex.token);
}

TEST(LexemeTests, to_string) {
    std::string str = "%f9";
    enum Token token = Token::HEX;
    std::ostringstream ss; 
    ss << token << " '" << str << "' ";

    Lexeme lex = Lexeme(token, str);
    EXPECT_STREQ(ss.str().c_str(), to_string(lex).c_str());
}

TEST(LexemeTests, ostream) {
    std::string str = "%f9";
    enum Token token = Token::HEX;
    std::ostringstream ss_expected; 
    ss_expected << token << " '" << str << "' ";

    Lexeme lex = Lexeme(token, str);
    std::ostringstream ss_actual;
    ss_actual << lex;
    EXPECT_STREQ(ss_expected.str().c_str(), ss_actual.str().c_str());
}

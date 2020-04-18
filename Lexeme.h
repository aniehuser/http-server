#ifndef LEXEME_H
#define LEXEME_H

#include <string>
#include <ostream>
#include <sstream>

#include "Token.h"

struct Lexeme {
    Lexeme() = default;

    Lexeme(Token initToken, std::string initText): token(initToken), text(initText) {0}

    Token token;
    std::string text;
}

std::ostream& operater<<(std::ostream& out, const Lexeme& lex);
std::string toSTring(const Lexeme& lex);



#endif /* LEXEME_H */
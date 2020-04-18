#ifndef TOKENS_H
#define TOKENS_H

#include <ostream>
#include <string>

enum class Token {
#define x(ident) ident,
    #include "token-include.h"
#undef x
};

/* Provide an output operator allowing Tokens to be outputted to std::cout
 or to any other ostream using << */
std::ostream& operator<<(std::ostream& out, Token token);
std::string to_string(Token token);

#endif /* TOKENS_H */

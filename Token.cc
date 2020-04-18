#include "Token.h"

/* Provide an output operator allowing Tokens to be outputted to std::cout
 or to any other ostream using << */
std::ostream& operator<<(std::ostream& out, Token token) {
    out << to_string(token);
    return out;
}

/* Use the x-macro pattern to create a giant switch statement to return a
 string representations of the passed-in token */
std::string
to_string(enum Token token) {
    switch(token) {
        #define x(ident)       \
            case Token::ident: \
                return #ident; 
                #include "token-include.h"
        #undef x
    }
}

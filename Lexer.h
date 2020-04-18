#include <string>
#include <sstream>

#include "Lexeme.h"

class Lexer {
public:
    Lexer(std::istream &init_in);
    Lexeme next_method();
    Lexeme next_uri();
    Lexeme next_version();
    Lexeme next_header();
    Lexeme next_body();
    bool atEOF();

private:
    char peek();
    char read();
    void eat_lws();
    char eof();
    bool is_hex();
    Lexeme single_char_lexeme(Token token);
    string read_next_string(char stop);
    
    std::istream &in;

};

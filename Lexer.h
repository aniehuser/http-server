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
    Lexeme next_body(int length);
    bool at_eof();

private:
    char peek();
    char read();
    void eat_lws();
    char eof();
    bool is_hex(char c);
    Lexeme single_char_lexeme(Token token);
    std::string read_next_string(char stop);
    
    std::istream &in;

};

#include <string>
#include <sstream>

#include <Lexer.h>

Lexer::Lexer(std::istream &init_in): in(init_in) {
    // TODO check for init_in is not false?
}

Lexeme
Lexer::next_method() {
    eat_lws();
    std::string str = read_next_string(NULL);
    if(str == "GET") return Lexeme(Token::GET, str);
    else if(str == "POST") return Lexeme(Token::POST, str);
    else if(str == "HEAD") return Lexeme(Token::HEAD, str);
    else { /* ERROR reutrn 501*/}

}

void
Lexer::eat_lws() {
    char curr = peek();
    while(curr != ' ' && curr != '\t') {
        read();
        curr = peek();
    }
}

char
Lexer::read() {
    return in.get();
}

char
Lexer::peek() {
    return in.peek();
}

std::string
Lexer::read_next_string(char stop) {
    char tmp;
    std::ostringstream oss:
    do {
        oss << read();
        if(at_eof()) {
            // TODO: throw exception?
        }
        tmp = peek();
    } while(tmp != '\n' && tmp != '\t' && tmp != ' ' && (stop != 0 && tmp != stop));
    return oss.str();
}


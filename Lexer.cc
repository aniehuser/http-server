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
    """ONLY SUPPORT GET FOR NOW"""
    // else if(str == "POST") return Lexeme(Token::POST, str);
    // else if(str == "HEAD") return Lexeme(Token::HEAD, str);
    else { /* ERROR return 501*/}
}

Lexeme
Lexer::next_uri() {
    eat_lws();
    char tmp = peek();
    
    if(tmp == '%') {
        std::ostringstream oss;
        read(); // remove '%'
        for(int i=0; i<2; i++) {
            tmp = peek();
            if(is_hex(tmp)) {
                oss << read();
            } else {
                 /* SOME ERROR, unsafe character used inappropriately*/
            }
        }
        return Lexeme(Token::ESCAPE, oss.str());
    } else if((tmp >= 'a' && <= 'z') || (tmp >= 'A' && tmp <= 'Z')) {
        return single_char_lexeme(Token::ALPHA);
    } else if(tmp >= 0 && tmp <= 9) {
        return single_char_lexeme(Token::DIGIT);
    } else if(tmp == '\r') {
        read();
        tmp = peek();
        if(tmp == '\n') {
            read()
            return Lexeme(Token::CRLF, "\r\n");
        } else {
            return Lexeme(Token::CR, "\r");
        }
    } 

    switch(tmp) {
        case '\n':
            return single_char_lexem(Token::LF);
            break;
        case ' ':
            return single_char_lexem(Token::SLASH);
            break;
        case '':
            return single_char_lexem(Token::SEMICOLON);
            break;
        case ';':
            return single_char_lexem(Token::SEMICOLON);
            break;
        case ';':
            return single_char_lexem(Token::SEMICOLON);
            break;
        case ';':
            return single_char_lexem(Token::SEMICOLON);
            break;
        case ';':
            return single_char_lexem(Token::SEMICOLON);
            break;
        case ';':
            return single_char_lexem(Token::SEMICOLON);
            break;
        case ';':
            return single_char_lexem(Token::SEMICOLON);
            break;
        case ';':
            return single_char_lexem(Token::SEMICOLON);
            break;
        case ';':
            return single_char_lexem(Token::SEMICOLON);
            break;
        case ';':
            return single_char_lexem(Token::SEMICOLON);
            break;
        case ';':
            return single_char_lexem(Token::SEMICOLON);
            break;
        case ';':
            return single_char_lexem(Token::SEMICOLON);
        case '"':
        case '#':
        case '<':
        case '>':
        
            break;
        
    }
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

Lexeme
Lexer::single_char_lexeme(Token token) {
    std::string str(1, read());
    return Lexeme(token, str);
}

bool
Lexer::is_hex(char c) {
    return (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F') || (c >= '0' && c <= '9')
}

bool Lexer::is

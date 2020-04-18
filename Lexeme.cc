#include "Lexeme.h"

std::ostream& operator<<(std::ostream& out, const Lexeme& lex) {
    out << lex.token << " '" << lex.text << "' ";
    return out;
}

std::string to_string(const Lexeme &lex) {
    std::ostringstream oss;
    oss << lex;
    return oss.str();
}

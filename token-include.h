/*
Define http specific tokens using x-macro pattern
*/

// METHODS
X(GET)  // "GET"
X(HEAD) // "HEAD"
X(POST) // "POST"

// HTTP VERSION
X(HTTP) // "HTTP"

// CHARACTERS
X(CRLF)         // \r\n
X(CR)           // \r
X(LF)           // \n
X(SP)           // Space character (20)
X(HT)           // \t
X(COLON)        // :
X(POUND)        // #
X(SEMICOLON)    // ;
X(SLASH)        // /
X(PLUS)         // +
X(MINUS)        // -
x(PERIOD)       // .
X(AT)           // @
X(QMARK)        // ?
X(AND)          // &
X(EQUAL)        // =
X(PERCENT)      // %
X(EXMARK)       // !
X(ASTERIKS)     // *
X(APOSTROPHE)   // ' 
X(LPAREN)       // (
X(RPAREN)       // )
X(COMMA)        // ,
X(DOLLAR)       // $
X(UNDERSCORE)   // _
X(QUOTE)        // "
X(LESSTHAN)     // <
X(GREATERTHAN)  // >

X(ALPHA)        // a-zA-Z
X(DIGIT)        // 0-9
X(ESCAPE)       // % HEX HEX
X(UNSAFE)       // CTL, SP, ;;

// SEARCH Tokens. Can specify to LEXER to prioritze search on specific tokens
X(CHAR)         // octets 0-127
X(OCTET)        // any 8 bit sequence of data
X(TEXT)         // Any octet except CTLs, including LWS
X(HEX)          // a-fA-F0-9

/*
Define http specific tokens using x-macro pattern
*/

// METHODS                                                 
x(GET)                                              
x(HEAD)                                             
x(POST)                                             
                                                    
x(HTTP)                                             
                                                    
x(CRLF)       /* \r\n */                            
x(CR)         /* \r */                              
x(LF)         /* \n */                              
x(SP)         /* Space character */                 
x(HT)         /* \t */                              
x(COLON)      /* : */                               
x(POUND)      /* # */                               
x(SEMICOLON)  /* ; */                               
x(SLASH)      /* / */                               
x(PLUS)       /* + */                               
x(MINUS)      /* - */                               
x(PERIOD)     /* . */                               
x(AT)         /* @ */                               
x(QMARK)      /* ? */                               
x(AND)        /* & */                               
x(EQUAL)      /* = */                               
x(PERCENT)    /* % */                               
x(EXMARK)     /* ! */                               
x(ASTERIKS)   /* * */                               
x(APOSTROPHE) /* ' */                               
x(LPAREN)     /* ( */                               
x(RPAREN)     /* ) */                               
x(COMMA)      /* , */                               
x(DOLLAR)     /* $ */                               
x(UNDERSCORE) /* _ */                               
x(QUOTE)      /* " */                               
x(LESSTHAN)   /* < */                               
x(GREATERTHAN)/* > */                               
                                                    
x(ALPHA)      /* a-zA-Z */                          
x(DIGIT)      /* 0-9 */                             
x(ESCAPE)     /* % HEX HEX */                       
x(UNSAFE)     /* CTL, SP, ; */                      
                                                    
/* SEARCH Tokens. Can specify */                    
/* to LEXER to prioritze      */                    
/* search on specific tokens  */                    
x(CHAR)  /* octets 0-127 */                         
x(OCTET) /* any 8 bit sequence of data */           
x(TEXT)  /* Any octet except CTLs, including LWS */ 
x(HEX)   /* a-fA-F0-9 */
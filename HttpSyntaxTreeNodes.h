#include <sys/types.h>

class Visitor {/*Mock, to delete*/};

class HSTNode {
public:
    virtual ~HSTNode(){}
    virtual void accept(Visitor& visitor) = 0;
};

class RequestUri: public HSTNode {
};

class AbsoluteUri: public RequestUri {
public:             /* scheme ":" *( uchar | reserved ) */
    char * scheme;  /* 1*( ALPHA | DIGIT | "+" | "-" | "." ) */
    char * rest;    /* *( uchar | reserved ) */
};

class Param: public HSTNode {
public:             /* *( pchar | "/" ) */
    char * value;
};

class AbsolutePath: public RequestUri {
public:                 /* [ path ] [ ";" params ] [ "?" query ] */
    char * path;        /* fsegment *( "/" segment ) */
    Param * params;     /* param *( ";" param ) */
    char * query;       /* *( uchar | reserved ) */
};

class RequestMethod: public HSTNode {
public:
    char * value;
    uint8_t flag;
}

class RequestLine: public HSTNode {
public:                             /* Method SP Request-URI [ SP HTTP-Version ] CRLF */
    RequestMethod * request_method; /* "GET" | "HEAD" | "POST" */
    RequestUri * request_uri;       /* absoluteURI | abs_path */
    char * http_version;            /* "HTTP" "/" 1*DIGIT "." 1*DIGIT */
};

class HeaderValue: public HSTNode {
public:

};

class Header: public HSTNode {
public:
    char * key;
    HeaderValue * value;
};

class EntityHeader: public Header {
public:

};

class GeneralHeader: public Header {
public:

};

class RequestHeader: public Header {

};

class Request: public HSTNode {
            /* Simple-Request | Full-Request */
};

class SimpleRequest: public Request {
public:    /* "GET" SP Request-URI CRLF */
    RequestLine * request_line;
};

class FullRequest: public Request {
public:                             /* Request-Line
                                       *( General-Header
                                        | Request-Header
                                        | Entity-Header )
                                       CRLF
                                       [ Entity-Body ] */
    RequestLine * request_line;
    EntityHeader * entity_headers;
    GeneralHeader * general_headers;
    RequestHeader * request_headers;
    char * entity_body;
};
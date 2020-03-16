#include <sys/types.h>
#include <map>
#include <string>

namespace constant
{
namespace method
{
    static const uint16_t GET        = 0x01;  // HTTP/0.9 and greater
    static const uint16_t HEAD       = 0x02;  // HTTP/1.0 and greater
    static const uint16_t POST       = 0x04;
    static const uint16_t PUT        = 0x08;  // HTTP/1.1 and greater
    static const uint16_t DELETE     = 0x10;
    static const uint16_t TRACE      = 0x20;
    static const uint16_t OPTIONS    = 0x40;
    static const uint16_t CONNECT    = 0x80;
}
namespace ver
{
    static const uint8_t v0_9       = 0x01;
    static const uint8_t v1_0       = 0x02;
    static const uint8_t v1_1       = 0x04;
    static const uint8_t v2_0       = 0x08;
}
// Status codes may need some rethinking
namespace code
{
    static const uint16_t CONTINUE = 100;
}
static std::map<uint16_t, std::string> reason {
    {100, "Continue"},
    {101, "Switching Protocols"},
    {102, "Processing"},
    {103, "Early Hints"},
    {200, "OK"},
    {201, "Created"},
    {202, "Accepted"},
    {203, "Non-Authoritative Information"},
    {204, "No Content"},
    {205, "Reset Content"},
    {206, "Partial Content"},
    {207, "Multi-Status"},
    {208, "Already Reported"},
    {226, "IM Used"},
    {300, "Multiple Choices"},
    {301, "Moved Permanently"},
    {302, "Found"},
    {303, "See Other"},
    {304, "Not Modified"},
    {305, "Use Proxy"},
    {306, "Switch Proxy"},
    {307, "Temporary Redirect"},
    {308, "Permanent Redirect"},
    {400, "Bad Request"},
    {401, "Unauthorized"},
    {402, "Payment Required"},
    {403, "Forbidden"},
    {404, "Not Found"},
    {405, "Method Not Allowed"},
    {407, "Proxy Authentication Required"},
    {408, "Request Timeout"},
    {409, "Conflict"},
    {410, "Gone"},
    {411, "Length Required"},
    {412, "Precondition Failed"},
    {413, "Payload Too Large"},
    {414, "URI Too Long"},
    {415, "Unsupported Media Type"},
    {416, "Range Not Satisfiable"},
    {417, "Expectation Failed"},
    {418, "I'm a teapot"},
    {421, "Misdirected Request"},
    {422, "Unprocessable Entity"},
    {423, "Locked"},
    {424, "Failed Dependency"},
    {425, "Too Early"},
    {426, "Upgrade Required"},
    {428, "Precondition Failed"},
    {429, "Too Many Requests"},
    {431, "Request Header Fields Too Large"},
    {451, "Unavailable For Legal Reasons"},
    {500, "Internal Server Error"},
    {501, "Not Implemented"},
    {502, "Bad Gateway"},
    {503, "Service Unavailable"},
    {504, "Gateway Timeout"},
    {505, "HTTP Version Not Supported"},
    {506, "Variant Also Negotiates"},
    {507, "Insufficient Storage"},
    {508, "Loop Detected"},
    {510, "Not Extended"},
    {511, "Network Authentication Required"}
};
}

struct http_request {
    const uint8_t version;
    const uint16_t method;
    const char * uri;
    const char ** headers;
    const char * body;
};

struct http_response {
    const uint8_t version;
    const uint16_t status_code;
    const char * reason;
    const char ** headers;
    const char * body;
};
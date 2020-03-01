#ifndef TCPSERVER_H
#define TCPSERVER_H
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAXLINE 255

class TcpServer {
public:
    TcpServer(uint32_t inaddr, uint16_t inport);
    ~TcpServer();
    void open();
    void start(char * (*handler)(int), int backlog);
    void close();
    bool isListening();
private:
    int listenfd, connfd;
    struct sockaddr_in servaddr;
    char * buff;
    bool listening;
};

#endif /* TCPSERVER_H */

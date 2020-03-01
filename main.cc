#include <iostream>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>
#include <string>
#include "TestInclude.h"
#include "TcpServer.h"

#define MAXLINE 255

char * mock_handler(int connfd) {
    // std::string str = "Handler Return String\n";
    return (char *) "Handler Return String\n";
}


int main(int argc, char **argv) {
    int ret = printSomething("Hello World!");

    TcpServer * serv = new TcpServer(INADDR_ANY, 8080);
    printSomething("constructed");
    serv->open();
    printSomething("openeded");
    serv->start(mock_handler, 10);
    printSomething("listnededd");
    serv->close();
    printSomething("closededldeing");
    delete serv;
    printSomething("fin dleeted");

    return ret;
}

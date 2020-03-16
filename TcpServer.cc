#include <stdlib.h>
#include <sstream>
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>
#include "TcpServer.h"
#include "TestInclude.h"

void Close(int fd);
void SysExit(int err);

TcpServer::TcpServer(uint32_t inaddr, uint16_t inport) {
    listening = false;
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family         = AF_INET;
    servaddr.sin_addr.s_addr    = htonl(inaddr);
    servaddr.sin_port           = htons(inport);
}

TcpServer::~TcpServer() {
}

void TcpServer::start(char * (*handler)(int), int backlog) {
    if((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cout << "Socket Create Failure" << std::endl;
        SysExit(-1);
    }

    if(bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        std::cout << "Bind Failure" << std::endl;
        SysExit(-1);
    }

    if(listen(listenfd, backlog) < 0) {
        std::cout << "Listen Failure" << std::endl;
        SysExit(-1);
    }

    listening = true;
    // Threadify/selectify/pollify ?
    for( ; ; ) {
        // connfd = accept(listenfd, NULL, NULL);
        buff = handler(connfd);
        printSomething(buff);
        // write(connfd, buff, strlen(buff));

        // Close(connfd);
        break;
    }
    listening = false;
}

void TcpServer::stop() {
    // TODO after threadify/pollify/selectify
    Close(connfd);
    Close(listenfd);
    listening = false;
}

bool TcpServer::isListening() {
    return listening;
}

void Close(int fd) {
    if(close(fd) < 0) {
        std::cout << "Faild to close fd" << std::endl;
        SysExit(-1);
    }
}

void SysExit(int err) {
    printf("Value of errno: %d\n", errno);
    exit(err);
}


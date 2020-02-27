#include <iostream>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>
#include "TestInclude.h"

// using namespace std;

#define MAXLINE 255

int main(int argc, char **argv) {
    int ret = printSomething("Hello World!");

    int					listenfd, connfd;
	struct sockaddr_in	servaddr;
	char				buff[MAXLINE];
	time_t				ticks;

	listenfd = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family      = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port        = htons(8080);

	if(bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        printSomething("bind error");
    }

	listen(listenfd, 5);

	for ( ; ; ) {
		connfd = accept(listenfd, NULL, NULL);

        ticks = time(NULL);
        snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
        write(connfd, buff, strlen(buff));

		close(connfd);
        break;
	}

    return ret;
}

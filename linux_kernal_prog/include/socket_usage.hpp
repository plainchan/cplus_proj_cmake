#ifndef SOCKET_USAGE_HPP
#define SOCKET_USAGE_HPP

#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
//连接服务端
int socket_timeout()
{

    
    struct sockaddr_in sockserv;

    memset(&sockserv,0,sizeof(sockaddr));
    sockserv.sin_family = AF_INET;
    sockserv.sin_port = htons(8000);
    sockserv.sin_addr.s_addr = inet_addr("192.168.9.181");

    int socket_fd = socket(AF_INET,SOCK_STREAM,0);
    if(socket_fd == -1)
    {
        std::cout << "socket error" << std::endl;
        return -1;
    }

    struct timeval timeout;
    timeout.tv_sec=8000;
    timeout.tv_usec=0;

    if(setsockopt(socket_fd,SOL_SOCKET,SO_SNDTIMEO,&timeout,sizeof(timeout))==-1)
    {
        std::cout << "setsockopt error" << std::endl;
        return -1;
    }

    int con_fd = connect(socket_fd,(struct sockaddr *)&sockserv,sizeof(sockserv));

    if(con_fd == -1)
    {
        if(errno == EINPROGRESS)
        {
            std::cout << "connect timeout" << std::endl;
            return -1;
        }
        std::cout << "connect server error" << std::endl;
        return -1;
    }
    return socket_fd;

}

void test_socket_timeout()
{
    int socket_fd = socket_timeout();
    std::cout << socket_fd << std::endl;
    close(socket_fd);
}





























#endif
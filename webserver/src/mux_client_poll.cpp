#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <sys/poll.h>
#include <sys/types.h>
#include<arpa/inet.h>

#define port 9006

int main(int argc,char **argv)
{
    int socket_fd;
    sockaddr_in servaddr;

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htonl(9006);
    poll();
    // select();

    return 0;
}
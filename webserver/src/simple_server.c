#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>  
#include<errno.h>  
#include<sys/types.h>  
#include<sys/socket.h>  
#include<netinet/in.h>  
#include<unistd.h>
#define DEFAULT_PORT 8000  
#define MAXLINE 4096  
int main(int argc, char** argv)  
{  
    int    socket_fd, connect_fd;  
    struct sockaddr_in     servaddr;  
    char    buff[4096];  
    int     n;  
    //初始化Socket  
    if( (socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1 )
    {  
        printf("create socket error: %s(errno: %d)\n",strerror(errno),errno);  
        exit(0);  
    }  
    //初始化  
    memset(&servaddr,0,sizeof(servaddr));   //string.h
    // bzero(&servaddr,sizeof(servaddr));   //strings.h 
    servaddr.sin_family = AF_INET;  
    servaddr.sin_addr.s_addr = htons(INADDR_ANY);//IP地址设置成INADDR_ANY,让系统自动获取本机的IP地址。  
    servaddr.sin_port = htons(DEFAULT_PORT);//设置的端口为DEFAULT_PORT  
    
    //将本地地址绑定到所创建的套接字上  
    if( bind(socket_fd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1)
    {  
        printf("bind socket error: %s(errno: %d)\n",strerror(errno),errno);  
        exit(0);  
    }  

    //开始监听是否有客户端连接  
    if( listen(socket_fd, 10) == -1)
    {  
        printf("listen socket error: %s(errno: %d)\n",strerror(errno),errno);  
        exit(0);  
    }  

    printf("======waiting for client's request======\n");  
    while(1)
    {  
        
        //等待客户端连接  
        if( (connect_fd = accept(socket_fd, (struct sockaddr*)NULL, NULL)) == -1)
        {  
 
            printf("accept socket error: %s(errno: %d)",strerror(errno),errno);  
            continue;  
        }  
        
        printf("here");
        //接受客户端传过来的数据  
        n = recv(connect_fd, buff, MAXLINE, 0); 

        //向客户端发送回应数据 
        //创建子进程 
        if(!fork())
        { 
            if(send(connect_fd, "Hello,you are connected!\n", 26,0) == -1)  
                perror("send error");  
            close(connect_fd);  
            exit(0);  
        }  
        buff[n] = '\0';  
        printf("recv msg from client: %s\n", buff);  
        close(connect_fd);  
    }  
    close(socket_fd);  
}  

// 客户端通过connect向服务器发起连接时，
// connect将首先发送同步报文段给服务器，然后等待服务
// 器返回确认报文段。如果服务器的确认报文段没有立即到达客户端，
// 则connect调用将被挂起，直到客户端收到确认报文段并唤醒connect调用。
// socket的基础API中，可能被阻塞的系统调用包括accept、send、
// recv和connect。
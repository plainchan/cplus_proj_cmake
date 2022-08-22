#ifndef SIGNAL_USAGE_HPP
#define SIGNAL_USAGE_HPP

#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "signal.h"




void Handler_exit(int sig)
{
    printf("receive signal %d\n",sig);
    for(int i=0;i<10;++i)
    {
        printf("hello world\n");
        usleep(100*1000);
    }
    exit(0);
}

void Handler_fun(int sig)
{
    printf("receive signal %d\n",sig);
    for(;;)
    {
        printf("hello world,just for fun\n");
        usleep(50*1000);
    }
}


void simple_signal_test()
{
    for(int i=0;i<100;++i)
        signal(i,SIG_IGN);  //SIG_IGN表示忽略目标信号,SIG_DFL表示使用信号的默认处理

    signal(SIGINT,Handler_exit);
    signal(SIGTERM,Handler_exit);
    signal(SIGQUIT,Handler_fun);

    while(true)
    {
        printf("loop\n");
        sleep(1);
    }
}

























#endif
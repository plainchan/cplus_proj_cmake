#ifndef PTHREAD_USAGE_HPP
#define PTHREAD_USAGE_HPP


#include<pthread.h>
#include<unistd.h>
#include<stdio.h>

void* work(void *arg)
{
    printf("thread ID %ld\n",pthread_self());
    int *n = (arg==NULL)?0:(int*)arg;
    for(int i=0;i<*n;++i)
    {
        usleep(100*1000);
        printf("Thead hello world %d\n",i);
    }
    // 线程函数在结束时最好调用如下函数，以确保安全、干净地退出
    pthread_exit(NULL);
}



void test_pthread()
{
    pthread_t t;
    int count = 10;
    pthread_attr_t attr;
    
    pthread_create(&t,NULL,work,(void*)&count);

    printf("Main thread ID %ld\n",pthread_self());

    int n = 10;
    while(n-->0)
    {
        usleep(50*1000);
        printf("main hello world %d\n",n);
    }

    pthread_join(t,NULL);
    
}



























#endif
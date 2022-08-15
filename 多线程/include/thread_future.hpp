#ifndef THREAD_FUTURE_HPP
#define THREAD_FUTURE_HPP


#include <future>
#include <mutex>
#include <condition_variable>

#include <queue>

#include <ctime>
#include <unistd.h>

#include <iostream>


long calcuSum(long n)
{
    long sum = 0;
    for(long i=0;i<n;++i)
        sum+=i;
    return sum;
}
void waitDataReady()
{
    sleep(1);
}
void test_doAsyncWorkWhenWait()
{
    std::future<long> doSum = std::async(calcuSum,2000000000);
    waitDataReady();
    std::cout<<"Sum is "<<doSum.get()<<std::endl;
}


















#endif
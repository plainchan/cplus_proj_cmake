#include <iostream>
#include "mythreadpool.hpp"
#include "unistd.h"
using namespace std;

int calcuSum(int n,int t=0)
{
    int sum =0;
    for(int i=0;i<n;++i)
    {
        sum+=i;
        if(t>0)
            usleep(t);
    }
    return sum;
}


void test_mytheadpool()
{
    MyThreadPool threadpool(4);
    
    auto res1 = threadpool.addTask(calcuSum,100,1000*50);
    auto res2 = threadpool.addTask(calcuSum,100,1000*50);
    auto res3 = threadpool.addTask(calcuSum,100,1000*50);
    auto res4 = threadpool.addTask(calcuSum,100,0);

    cout << res4.get() << endl;
    cout << res1.get() << endl;
    cout << res2.get() << endl;
    cout << res3.get() << endl;
    
    threadpool.stop();
}
int main()
{


    test_mytheadpool();

    return 0;
}






#include <iostream>
#include "threadpool.hpp"
#include "unistd.h"
using namespace std;

class MyThreadPool;

int main()
{


    ThreadPool pool(3);   //创建三个线程

    auto res = pool.enqueue([](int n){
        int sum=0;
        for(int i=0;i<n;++i)
        {
            cout << i << " ";
            // usleep(500);
        }
        cout <<endl;
        return sum;
    },10000);
    auto res1 = pool.enqueue([](int n){
        int sum=0;
        for(int i=0;i<n;++i)
        {
            cout << i << " ";
            // usleep(500);
        }
        cout <<endl;
        return sum;
    },10000);

    res.get();
    res1.get();
    return 0;
}






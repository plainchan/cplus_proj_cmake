#ifndef SIMPLECASE_HPP
#define SIMPLECASE_HPP

#include <thread>
#include <iostream>
#include "unistd.h"



void threadHelloWorld()
{
    
    for(int i=0;i<10;++i)
    {
        std::cout << "Hello World by thread1," << i << std::endl;
        sleep(1);
    }
}



//函数对象
class  threadFun_obj
{
public:
    void operator() () const
    {
        std::cout << "Hello World by thread2 " << std::endl;
    }
};


/**
 * @brief 线程1分离或汇入,线程2等待主线程
 * 
 */
void test_join_detach()
{


    std::thread t1(threadHelloWorld);

    threadFun_obj f;
    //如果你传递了一个临时变量，而不是一个命名的变量。C++编译器会将其解析为函
    //数声明，而不是类型对象的定义。
    // std::thread t2(f);   //std::thread t(threadFun_obj()); 错误不能传入临时变量
    std::thread t2((threadFun_obj()));
   
    int cnt = 0;
    while(cnt++ < 5)
    {
        std::cout << "Hello  Kitty" << std::endl;
        sleep(1);
    }


    // join的时机非常关键,一旦join,就会阻塞线程
    // 创建线程后即join,就会阻塞程序,等待该线程执行完毕,等同于没有多线程
    // join时机:在主线程快结束,该线程还没有结束的时候join;在该线程快结束,主线程还没有结束的时候,直接在主线程末尾join
    // 为了销毁一个C++线程对象，要么join()函数需要被调用（并结束）

    t1.join();  //阻塞线程，等待线程完成，防止main线程结束时，此线程还没有结束
    // ！！！！！！！！！不能在此线程中访问主线程的局部变量！！！！！！！！！！！！！
    // t1.detach();  //脱离主线程，即使主线程结束也继续运行，

    t2.join();  //阻塞线程，等待线程完成，防止main线程结束时，此线程还没有结束 

    // !!!!!!!!!!!!应该在执行流程到析构函数前总是要么join，要么detach一个线程!!!!!!!!!!!!!!!!!!!
    
}


void test_hardware_concurrency()
{
    std::cout << "线程数量或者核芯数:" << std::thread::hardware_concurrency() << std::endl;
}



#endif
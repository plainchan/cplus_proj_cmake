#ifndef SIMPLECASE_HPP
#define SIMPLECASE_HPP

#include <thread>
#include <iostream>
#include <memory>
void printHelloWorld()
{
    for(int i=0;i<100000;++i);
        std::cout << "Hello World" << std::endl;
}

void threadJoinOrDetach()
{
    std::thread t(printHelloWorld);
    t.join();  //阻塞线程，等待线程完成，防止main线程结束时，此线程还没有结束

    // ！！！！！！！！！不能在此线程中访问主线程的局部变量！！！！！！！！！！！！！
    // t.detach();  //脱离主线程，即使主线程结束也继续运行，
}

//函数对象
class  fun_obj
{
public:
    void operator() () const
    {
        printSomething();
        printSomethingElse();
    }

    void printSomething() const
    {
        std::cout << "print something" << std::endl;
    }
    void printSomethingElse() const
    {
        std::cout << "print something else" << std::endl;
    }

};
//传递函数对象给线程
void threadFuncObj()
{
    fun_obj f;
    //如果你传递了一个临时变量，而不是一个命名的变量。C++编译器会将其解析为函
    //数声明，而不是类型对象的定义。
    std::thread t(f);   //std::thread t(fun_obj()); 错误不能传入临时变量
   
    t.join();  //阻塞线程，等待线程完成，防止main线程结束时，此线程还没有结束
}



#endif
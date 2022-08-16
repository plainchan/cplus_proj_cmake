#ifndef TEST_BIND_HPP
#define TEST_BIND_HPP

#include <functional>
#include <iostream>


// std::bind函数看作一个通用的函数适配器，它接受一个可调用对象，生成一个新的可调用对象来“适应”原对象的参数列表
// 将可调用对象和其参数绑定成一个仿函数

//函数绑定函数
int add(int x,int y)
{

}
void calcu()
{

}

void test()
{

}


//类成员函数绑定非成员函数
void myMessage(std::string s)
{
    std::cout << s << std::endl;
}
class processMessage
{
public:
    void processBind( void(*callback)(std::string))
    {
        auto callback1 = std::bind(callback,std::placeholders::_1);
        std::cout << typeid(decltype(callback)).name() << std::endl;
        std::cout << typeid(decltype(callback1)).name() << std::endl;


    }
    void process(std::string &s)
    {
        // callback(std::string("ssdsfdsf"));
    }   
private:
    std::function<void(std::string)> callback;
};
void test2()
{
    processMessage p;
    p.processBind(myMessage);
    std::string s ="123456";
    p.process(s);
}

// 类成员函数绑定非成员函数做回调函数
// A类成员函数绑定B类成员函数
// Calculator处理操作由User制定
class Calculator
{
public:
    template<class T>
    std::function<int(int,int)> calcuMethod(int (T::*callback)(int,int),T *obj)
    {
        std::function<int(int,int)> callbackFunction =  std::bind(callback,obj,std::placeholders::_1,std::placeholders::_2);
        return  callbackFunction;
    }
};
class UserCalcu
{
public:
    UserCalcu()
    {
        calcu = new Calculator();
        callback=calcu->calcuMethod(&UserCalcu::Add,this);
    }
    ~UserCalcu()
    {
        if(calcu!=nullptr)
            delete calcu;
    }

    int getValue(int x,int y)
    {
        return callback(x,y);
    }
    int Add(int x,int y)
    {
        
        return x+y;  
    }

private:
    using Callback =std::function<int(int,int)>;
    Calculator *calcu;
    Callback callback;
};

void test3()
{
    UserCalcu user;
    std::cout << user.getValue(1,6) << std::endl;

}

























#endif
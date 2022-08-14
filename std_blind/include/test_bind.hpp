#ifndef TEST_BIND_HPP
#define TEST_BIND_HPP

#include <functional>
#include <iostream>


// std::bind函数看作一个通用的函数适配器，它接受一个可调用对象，生成一个新的可调用对象来“适应”原对象的参数列表
// 将可调用对象和其参数绑定成一个仿函数

//函数绑定函数



// std::function<void(int,int)> f = std::bind(&processData,std::placeholders::_1,std::placeholders::_2);



// 类成员函数绑定自身的类成员函数做回调函数
class Node
{

};

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

void test()
{
    UserCalcu user;
    std::cout << user.getValue(1,6) << std::endl;

}

























#endif
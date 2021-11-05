#ifndef EXAMPLE_HPP
#define EXAMPLE_HPP

#include <iostream>

/*
* 友元函数与友元类
* 一个类的私有变量和成员函数，这个类的对象是不能访问的
* 如何一个函数或类被声明另一个类的友元
* 则这个友元函数或友元类中建立的类的对象，就可以访问其私有成员或成员函数
*/

class Num;

//全局函数作友元
std::pair<int, int> getNum(Num *num);


//成员函数作友元
class A
{
public:
    static std::pair<int, int> getNum(Num *num);

};


//类作友元
class B
{
public:
    B(int m,int n);
    ~B();
    std::pair<int,int> getNum();
private:
    Num *p;  
};


//类Num定义
class Num
{
    friend std::pair<int, int> getNum(Num *num);
    friend std::pair<int, int> A::getNum(Num *num);
    friend B;

public:
    Num(){};
    Num(int m, int n) //不能用初始化列表初始化静态成员变量
    {
        this->m = m;
        this->n = n;
    }

private:
    static int m;
    static int n;
};
int Num::m = 1;
int Num::n = 2;


//全局函数做友元函数
std::pair<int, int> getNum(Num *num)
{
    return std::make_pair(num->m, num->n);
}

//成员函数作友元
std::pair<int, int> A::getNum(Num *num) 
{   
    return std::make_pair(num->m, num->n);
}


//类作友元
//在类B中新建一个Num类对象
//将类B作Num类的友元，则Num类对象可以访问私有变量
B::B(int m, int n)
{
    p = new Num(m,n);
}
B::~B()
{
    if(p != nullptr)
        delete p;
}
std::pair<int,int> B::getNum() 
{
    //直接访问类的私有变量
    return std::make_pair(p->m,p->n);
}




#endif
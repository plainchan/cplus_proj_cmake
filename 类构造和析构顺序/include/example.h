#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <iostream>

using namespace std;

/****************************************
* 继承中:先调用父类构造函数, 再调用子类构造函数，
*       先调用子类析构函数, 再调用父类析构函数.
*       构造顺序 与 析构顺序 相反.
*****************************************/

class Parent
{
public:
    Parent()
    {
        cout << "父类构造函数" << endl;
    };
    ~Parent()
    {
        cout << "父类析构函数" << endl;
    };
};

class Son : public Parent
{
public:
    Son()
    {
        cout << "子类构造函数" << endl;
    };
    ~Son()
    {
        cout << "子类析构函数" << endl;
    };
};

/****************************************
*顶层类的构造函数声明另一个类:
*        按照顶层类的构造和析构的代码顺序执行
*        先执行顶层类的构造函数,程序结束时执行顶层类的析构函数
*        被构造的另一个类就是代码段而已，轮到构造就构造，轮到析构就析构
*        被构造的另一个类在其构造函数执行完毕后，再继续执行并完成顶层类的构造，其实就是按照代码顺序依次执行
*       
*****************************************/

class Friend
{
public:
    Friend()
    {
        cout << "Friend构造函数" << endl;
    };
    ~Friend()
    {
        cout << "Friend析构函数" << endl;
    };
};


class Person
{
public:
    Person()
    {
        cout << "Person构造函数" << endl;
        p = new Friend();
        cout << "Person构造函数进行中>>>>>>>>" << endl;
        
    };
    ~Person()
    {
        cout << "Person析构函数" << endl;
        if(p != NULL)
            delete p;
        cout << "Person析构函数进行中>>>>>>>>" << endl;
    };

private:
    Friend *p;
};

///嵌套类？？
///局部类？？
///待了解中........


#endif
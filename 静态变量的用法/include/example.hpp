#ifndef __EXAMPLE_H__
#define __EXAMPLE_H__

#include <iostream>


//全局静态变量
//cpp（源文件）文件中定义静态变量，其作用域限定该文件中

//局部静态变量
//作用域同普通局部变量，生存周期为整个程序运行期间


/*
*static 存储类指示编译器在程序的生命周期内保持局部变量的存在，而不需要在每次它进入和离开
*作用域时进行创建和销毁。因此，使用 static 修饰局部变量可以在函数调用之间保持局部变量的值。
*/
void keepLocalValueLive()
{
  static int count = 0;
  int num = 0;
  std::cout << "static局部变量number =" << ++count << std::endl;
  std::cout << "局部变量num =" << ++num << std::endl;
}

void test_keepLocalValueLive()
{
    int i = 10;
    while(i-->0)
        keepLocalValueLive();
}



//返回局部静态变量
int* getStaticLovalValue()
{
    static int count = 0;

    return &(++count);
}

void test_getStaticLovalValue()
{
    int i = 10;
    while(i-->0)
        std::cout << "返回局部静态变量: "<< *getStaticLovalValue()<< std::endl;
}


















#endif
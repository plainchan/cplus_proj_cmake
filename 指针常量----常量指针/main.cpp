#include <iostream>

using namespace std;

void test1()
{
  //指针常量 --> 一个指针类型的常变量
  //指针指向的地址不能修改，但是可以更改指针指向的变量值
  cout << "----------指针常量-----------" << endl;
  int num = 100;
  int *const p = &num;
  cout << "num = " << num << endl;
  cout << "*p = " << *p << endl;
  cout << "p 指针地址 " << p << endl;

  *p = 200;
  cout << "num = " << num << endl;
  cout << "*p = " << *p << endl;
  cout << "p 指针地址 " << p << endl;
}

void test2()
{
  // 常量指针 ->指向常量的指针变量
  //指针指向的地址可以修改，但是可以不能更改指针指向的变量值num
  cout << "----------常量指针-----------" << endl;
  int num = 100;
  const int* p = &num;

  cout << "num = " << num << endl;
  cout << "*p = " << *p << endl;
  cout << "p 指针地址 " << p << endl;

  num = 200;
  cout << "*p = " << *p << endl;
  // *p = 200;
}

void test3()
{
  //常指针常量
  //指针不能改变，指针指向的值也不能改变
  cout << "----------常指针常量-----------" << endl;
  int num = 100;
  const int* const p = &num;
  cout << "num = " << num << endl;
  cout << "*p = " << *p << endl;
  cout << "p 指针地址 " << p << endl;
}

void test4()
{
  //删除空指针不会报错
  int *p = nullptr;
  delete p;
}


int main()
{


  test4();


  return 0;
}
#include <iostream>
#include "example.h"
using namespace std;
/*
* 创建对象的同时，将静态成员变量加1,因为类对象共享静态变量，所以静态被同步修改
*/
int main(int argc, char **argv)
{

  cout << "创建第一个对象" << endl;
  NumPlus num1;
  num1.print();

  cout << "创建第二个对象" << endl;
  NumPlus num2;
  num1.print();
  num2.print();

  cout << "创建第三个对象" << endl;
  NumPlus num3;
  num1.print();
  num2.print();
  num3.print();
  
  return 0;
}


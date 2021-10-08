using namespace std;
#include <iostream>
/*
*static 存储类指示编译器在程序的生命周期内保持局部变量的存在，而不需要在每次它进入和离开
*作用域时进行创建和销毁。因此，使用 static 修饰局部变量可以在函数调用之间保持局部变量的值。
*/
void keepLocalValueLive()
{
  static int number = 100;
  cout << "static局部变量number =" << number << endl;
  number++;
}

/*
* 每次进入函数或离开函数都会创建和销毁和局部变量
*/
void LocalValueDestroye()
{
  int number = 100;
  cout << "局部变量number =" << number << endl;
  number++;
}

#include "example.h"

using namespace std;

// 静态全局变量,只能在定义该变量的源文件内有效，在同一源程序的其它源文件中不能使用它。
static int static_number_global = 250;

void keepLocalValueLive();
void LocalValueDestroye();

int main()
{ 
  cout << "全局变量number_global = " << number_global << endl;
  cout << "全局变量static_number_global = " << static_number_global << endl;

  int cnt = 0;
  while(true)
  {
    cnt++;
    keepLocalValueLive();
    LocalValueDestroye();
    if(cnt >5)
      break;
  }
 
  return 0;
}


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
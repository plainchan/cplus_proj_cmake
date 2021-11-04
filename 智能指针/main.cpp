#include <iostream>
#include <memory>
using namespace std;

/*
* 智能指针的行为类似常规指针，重要的区别是它负责自动释放所指向的对象。
* shared_ptr允许多个指针指向同一个对象，unique_ptr则“独占”所指向的对象。
* 标准库还定义了一种名为weak_ptr的伴随类，它是一种弱引用，指向shared_ptr所管理的对象，
* 这三种智能指针都定义在memory头文件中。
*/

int main()
{
  
  shared_ptr<int> p1;
  //将p1作为一个条件判断shared_ptr<int> p1;，若p1指向一个对象，则返回true
  cout << "********智能指针名称做条件判断*******" << endl;
  if (p1)
    cout << "智能指针已经指向对象" << endl;
  else
    cout << "智能指针为空(未指向实体)" << endl;

  //构建对象
  cout << "********构建对象 引用*******" << endl;
  // p1 = make_shared<int>(5);
  p1(new int(100));
  //解引用，获取他的指向对象
  cout << "*p1 = " << *p1 << endl;

  //拷贝,两个指针指向同一个对象
  cout << "********拷贝*******" << endl;
  shared_ptr<int>p2(p1);     //会递增p1指向对象的引用次数
  cout << "p1.use_count()  = " << p1.use_count() << endl;
  cout << "p2.use_count()  = " << p2.use_count() << endl;
  cout << "*p2 = " << *p2 << endl;

  
  shared_ptr<int> p3(new int(100));
  // shared_ptr<int> p3 = new int(100); //错误,普通指针不能隐式转换智能指针
  shared_ptr<int> p4(p3);
  cout << "p3.use_count()  = " << p3.use_count() << endl;
  cout << "p4.use_count()  = " << p3.use_count() << endl;
  p3 = p1;   //递减p3指向对象的引用次数，递增p1指向对象的引用次数
  cout << "p1.use_count()  = " << p1.use_count() << endl;
  cout << "p3.use_count()  = " << p3.use_count() << endl;
  cout << "p4.use_count()  = " << p4.use_count() << endl;
  cout << "*p4  = " << *p4 << endl;



  return 0;
}
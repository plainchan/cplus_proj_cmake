#ifndef __EXAMPLE_H__
#define __EXAMPLE_H__
/*                      类静态成员:实现同类的多个对象之间数据共享
*1. 静态成员在类的所有对象中是共享的,无论创建多少个类的对象，静态成员都只有一个副本。
*2. 如果只声明了类而未定义对象，则类的非静态数据成员是不占存储空间的，只有在定义对象时，才为对象的数据成员分配空间。
*3. 不能把静态成员的初始化放置在类的定义中，但是可以在类的外部通过使用范围解析运算符 :: 来重新声明静态变量从而对它进行初始化。
*4. 如果不存在其他的初始化语句，在创建第一个对象时，所有的静态数据都会被初始化为零。
*5. 有了静态数据成员，各对象之间实现了数据共享，因此可以不使用全局变量。 
*6. 静态数据成员也遵从public、protect、private访问规则,private、protect的static成员虽然可以在类外初始化，但是不能在类外被访问。
*/
class NumPlus
{
  static int num;   //未声明访问类型，默认为private

public:

  NumPlus();
  void print();

};

#endif

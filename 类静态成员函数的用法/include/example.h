#ifndef __EXAMPLE_H__
#define __EXAMPLE_H__
/*        一般情况下，静态成员函数主要是用来访问全局变量或者同一个类中的静态数据成员    
*1. 静态成员函数是类的一部分，而不是对象的一部分
*2. 静态成员函数即使在类对象不存在的情况下也能被调用，静态函数只要使用类名加范围解析运算符 :: 就可以访问。
*3. 静态成员函数只能访问静态成员数据、其他静态成员函数和类外部的其他函数。
*4. 静态成员函数有一个类范围，他们不能访问类的 this 指针。使用静态成员函数来判断类的某些对象是否已被创建。
*5. 静态成员函数可以在建立任何对象之前处理静态数据成员，这是普通成员函数不能实现的。
*/
class Polygon
{
public:
  Polygon(int sides);

  //静态成员函数用来初始化
  static void init();

  int calcuSumAngle();
  float rad(float degree);

  static void visitClassVlue(Polygon &poly)
  {
    // std::cout << "degree ==" <<poly.degree << std::endl;
    //静态成员函数不可访问类中的非静态成员。
    //如果确实需要，静态成员函数只能通过对象名（或指向对象名的指针）访问该对象的非静态成员
  }

  static float pi;

  float degree;
  int sides;
};

#endif
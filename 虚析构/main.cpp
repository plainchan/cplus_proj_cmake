#include<iostream>

using namespace std;
#include<string.h>
#define __OPTIMIZE__
int main()
{

// 1. 多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码
//    解决方式：将父类中的析构函数改为虚析构或者纯虚析构
// 2. 虚函数覆盖,子类会覆盖父类的方法(override)
//
// 3. 一个函数在基类申明一个virtual，那么在所有的派生类都是是virtual的。
//    无论它前面有没有virtual修饰，只要基类中的同名函数被virtual修饰，
//    那么编译器会自动给派生类中的同名函数加上virtual前缀
//
// 4. 在程序中加override(派生类中声明）关键字，可以避免派生类中忘记重写虚函数的错误
//
    class A
    {
    public:

        A(){std::cout << "A constructor" << std::endl;}
        virtual void foo()
        {
            std::cout << "A::foo() is called" << std::endl;
        }

        virtual ~A(){std::cout << "A析构" << std::endl;};  //虚析构
    };
    class B : public A
    {
    public:
        B(){std::cout << "B constructor" << std::endl;}
        virtual void foo() 
        {
            // array = new int[100];
            std::cout << "B::foo() is called" << std::endl;
        }
        ~B()
        {
            // delete[] array;
            std::cout << "B析构" << std::endl;
        }

        int *array;
    };

    B *bptr = new B();
    A* a = dynamic_cast<A*>(bptr);  //基类指针执行派生类
    a->foo();
    delete a;   //若基类的析构函数不是虚函数，将不会调用派生类的

    cout << strpbrk("152345","5 *9")<<endl;
    return 0;
}


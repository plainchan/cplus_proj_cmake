#ifndef EXAMPLE_HPP
#define EXAMPLE_HPP

#include <iostream>


// 纯虚函数     => 继承的是：接口 (interface)
// 普通虚函数   => 继承的是：接口 + 缺省实现 (default implementation)
// 非虚成员函数  =>继承的是：接口 + 强制实现 (mandatory implementation) 
void test1()
{
    class A
    {
    public:
        void foo()
        {
            std::cout << "A::foo() is called" << std::endl;
        }
    };  
    class B:public A
    {
    };

    B b;
    b.foo();
}

//抽象类
//    虚函数表　V-Table
//    同一个类的所有对象都使用同一个虚表。
//    为了指定对象的虚表，对象内部包含一个虚表的指针，来指向自己所使用的虚表。
// 　　当实例化一个对象时，会生成一个虚函数表指针成员，这个虚函数表指针与虚函数表同时出现，
// 　　虚函数表只有一个，而虚函数表指针指向虚函数表的首地址，在虚函数表中定义了一个函数指针，这个函数指针指向了虚函数的首地址，
//    基类将所有虚函数的地址依次排放
//    <1> 若派生类未覆盖基类虚函数:
//          虚函数按照其声明顺序放于表中。
//          父类的虚函数在子类的虚函数前面。
//    <2> 若派生类覆盖基类虚函数:
//          覆盖的函数被放到了虚表中原来父类虚函数的位置。
//          没有被覆盖的函数依旧。
void test2()
{
    //含有纯虚函数的类是抽象类
    //抽象类不可实例化
    class A
    {
    public:
        virtual void foo()=0;  
    };
    class B:public A
    {
    public:
        virtual void foo() override
        {
            std::cout << "B::foo() is called" << std::endl;
        }
    };

    // A a;  //抽象类不可实例化
    B b;
    b.foo();

    //每个对象的内部都有一个指向虚函数表的指针
    std::cout << sizeof(b) << std::endl;
}



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
void test3()
{
    class A
    {
    public:
        virtual void foo()
        {
            std::cout << "A::foo() is called" << std::endl;
        }

        virtual ~A(){std::cout << "A析构" << std::endl;};  //虚析构
    };
    class B : public A
    {
    public:
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
    A* a = static_cast<A*>(bptr);  //基类指针执行派生类
    a->foo();
    delete a;   //若基类的析构函数不是虚函数，将不会调用派生类的
}


// 没有使用虚函数，但是子类和父类函数同名，子类中的函数将隐藏父类的同名函数
// 使用作用域分辨符访问父类中的同名函数。
// 重载的概念：
//     重载函数的本质为多个不同的函数。
//     函数名和参数列表是唯一的标识。
//     函数重载必须发生在同一个作用域中。
// 此情况非重载，因为子类和父类在不同的作用域中
//
//！！！《Effective C++》条款: 决不要重新定义继承而来的非虚函数。!!!!
//在一个类中声明一个非虚函数实际上为这个类建立了一种特殊性上的不变性
//重新定义会破坏这种不变性
void test4()
{

    class A
    {
    public:
        void foo()
        {
            std::cout << "AA:foo was called" << std::endl;
        }

    };
    class B : public A
    {
    public:
        void foo()
        {
            std::cout << "BB:foo was called" << std::endl;
        }
    };

}
#endif
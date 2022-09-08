#include <iostream>

using namespace std;


void test1()
{
    class A
    {
    public:
        A(int num):a(num){}
        int a;
    };
    class B: public A
    {
    public:
        B(int num):b(num),A(0){}
        int b;
    };
    class C: public A
    {
    public:
        C(int num):c(num),A(1){}
        int c;
    };

    class D:public B,public C
    {
    public:
        D(int num=0):d(num),B(2),C(3)
        {

        }
        int d;
    };
    D d(4);

    //菱形继承
    //复制了两份基类
    //需要指明从哪一个继承得到的成员变量
    cout << d.C::a << endl;
}


//虚继承
void test2()
{
    
    class A
    {
    public:
        A(int num):a(num){}
        int a;
    };
    //菱形继承
    //虚继承
    //只对此基类生成一块内存区域
    class B:virtual public A
    {
    public:
        B(int num):b(num),A(0){}
        int b;
    };
    class C:virtual public A
    {
    public:
        C(int num):c(num),A(1){}
        int c;
    };

    class D:public B,public C
    {
    public:
        D(int num):d(num),A(100),B(2),C(3)
        {

        }
        int d;
    };
    D d(4);


    cout << d.a << endl;
}


int main()
{

    test2();
    return 0;
}
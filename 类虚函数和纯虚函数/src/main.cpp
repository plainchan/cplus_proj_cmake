#include "example.hpp"

using namespace std;

int main()
{
    //父类指针 指向 子类
    //A是指父类，A* p为定义一个父类的指针p,指向子类B.p指针本身是一个父类类型的，也指向A.一个树Tree和一个苹果树AppleTree.
    //一个树Tree和一个苹果树AppleTree.指针p既然指向了苹果树，肯定也指向树。
    A* p = new B();
    p->foo();




    return 0;
}
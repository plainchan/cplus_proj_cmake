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


    return 0;
}
#include <iostream>
#include <memory>
using namespace std;

/*
 * 智能指针的行为类似常规指针，重要的区别是它负责自动释放所指向的对象。
 * shared_ptr允许多个指针指向同一个对象，unique_ptr则“独占”所指向的对象。
 * 标准库还定义了一种名为weak_ptr的伴随类，它是一种弱引用，指向shared_ptr所管理的对象，
 * 这三种智能指针都定义在memory头文件中。
 */

//智能指针实际是一个对象，调用对象的函数要用操作符 “.”
//使用该对象指向的指针用 "->" 或“*”(智能指针重载了操作符)



// shared_ptr不仅可以访问指向的内存区域,而且还可以掌管指向区域的“生死大权”，
// 也就是说伴随着shared_ptr指针生命周期的结束，指针指向的区域也会被释放掉。
// weak_ptr不敢这样做，作为智能指针中最弱的一个，weak_ptr只能访问所指向的内存区域，
// 当weak_ptr指针生命结束之时，其所指向的内存依旧完好无损，
// 即weak_ptr无须参与管理所指涉到的对象的共享所有权

void test_weak_ptr_simplecase()
{
    shared_ptr<float> p = make_shared<float>(3.14);
    cout << "--------------use_count------------" << endl;
    cout << "use_count: " << p.use_count() << endl;
    weak_ptr<float> wp=p;                               //weak_ptr指针初始化只能靠shared_ptr指针赋值
    cout << "use_count: " << p.use_count() << endl;     //“weak_ptr并不影响shared_ptr引用计数指针的计数值，即weak_ptr不会影响指向区域内存的生命周期”
     
    cout << "--------------weap_ptr获取share_ptr指针指向------------" << endl;
    cout << "p address: " << p.get() << endl;          
    cout << "p address: " << wp.lock().get() << endl;   //lock成员函数：返回一个shared_ptr类型的指针 

    cout << "--------------weap_ptr检测share_ptr是否为空------------" << endl;
    // p.reset();
    cout << wp.expired() << endl;

    cout << "-----reset,swap,use_count成员函数同share_ptr-------" << endl;
}

//weak_ptr用法
//当两个对象的成员变量指针互相指向时，析构时会陷入死循环

#define use_share
class B;
class A
{
public:
    ~A()
    {
        cout << "A 析构" << endl;
    }
#ifdef use_share
    weak_ptr<B> ptr;
#else
    shared_ptr<B> ptr;
#endif
};

class B
{
public:
    ~B()
    {
        cout << "B 析构" << endl;
    }
#ifdef use_share
    weak_ptr<A> ptr;
#else
    shared_ptr<A> ptr;
#endif

};

void test_Point_to_each_other()
{
    shared_ptr<A> a =make_shared<A>();
    shared_ptr<B> b =make_shared<B>();
    a->ptr =b;
    b->ptr =a;

}

//weak_ptr作为一个观察者指针，每次使用share_ptr时，检测指针指向是否为空


int main()
{

    test_Point_to_each_other();
    return 0;
}
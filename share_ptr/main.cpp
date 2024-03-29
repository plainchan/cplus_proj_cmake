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
//使用该对象指向的指针用 "->" 或“*”

void test_share_simplecase()
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
    p1 = make_shared<int>(5);
    // p1=new int(100);  //错误,普通指针不能隐式转换智能指针
    //解引用，获取他的指向对象
    cout << "*p1 = " << *p1 << endl;


    

    //拷贝,两个指针指向同一个对象
    cout << "********拷贝*******" << endl;
    shared_ptr<int> p2(p1); //会递增p1指向对象的引用次数
    cout << "p1.use_count()  = " << p1.use_count() << endl;
    cout << "p2.use_count()  = " << p2.use_count() << endl;
    cout << "*p2 = " << *p2 << endl;

    cout << "********引用次数*******" << endl;
    shared_ptr<int> p3(new int(100));
    // shared_ptr<int> p3 = new int(100); //错误,普通指针不能隐式转换智能指针
    shared_ptr<int> p4(p3);
    cout << "p3.use_count()  = " << p3.use_count() << endl;
    cout << "p4.use_count()  = " << p4.use_count() << endl;
    p3 = p1;                 //递减p3指向对象的引用次数，递增p1指向对象的引用次数
    cout << "p1.use_count()  = " << p1.use_count() << endl;
    cout << "p3.use_count()  = " << p3.use_count() << endl;
    cout << "p4.use_count()  = " << p4.use_count() << endl;
    cout << "*p4  = " << *p4 << endl;



}

void test_share_ptr_modify()
{
    shared_ptr<float> p1 = make_shared<float>(3.1415926);

    cout << "------------重置指针--------------"<<endl;
    cout << "p address: " << p1 << endl;
    cout << "*p= " << *p1 << endl;
    p1.reset();
    cout << "---reset share_ptr---" << endl;
    cout << "p address: " << p1 << endl;
    // cout << "*p=" << *p1 << endl;  //error
}

void test_share_ptr_swap()
{
    shared_ptr<float> p1 = make_shared<float>(3.1415926);
    shared_ptr<float> p2 = make_shared<float>(100);

    cout << "*p1= " << *p1 << endl;
    cout << "*p2= " << *p2 << endl;
    cout << "------------swap--------------"<<endl;
    p1.swap(p2);
    // swap(p1,p2);
    cout << "*p1= " << *p1 << endl;
    cout << "*p2= " << *p2 << endl;

}

void test_share_ptr_get()
{
    shared_ptr<float> p1 = make_shared<float>(3.1415926);

    cout << "------------get--------------"<<endl;
    cout << "p1 address: " << p1 << endl;   
    cout << "p1 address: " << p1.get() << endl;  //此方法是否更安全？？
  
}

void test_share_ptr_unique()
{
    shared_ptr<float> p1 = make_shared<float>(3.1415926);

    cout << "------------unique--------------"<<endl;
    cout << "p1 unique: " << p1.unique() << endl;   
    
    shared_ptr<float> p2= p1;

    cout << "p1 unique: " << p1.unique() << endl;  //此方法是否更安全？？
  
}


//share_ptr不能指向局部变量
shared_ptr<int> get_local_value()
{
    int a = 100;
    shared_ptr<int> p =shared_ptr<int>(&a);
    cout << p.use_count() << endl; 
    return p;
}

void test_localValue_lifetime()
{
    auto p = get_local_value();
    // cout << *p << endl;  //error
    cout << p.use_count() << endl;
}


//实现share_ptr
template<class T>
class sharePtr
{
public:
    sharePtr():ptr(0),pcount(new int(0))
    {

    }
    sharePtr(T *p)
    {
        ptr=p;
        pcount=new int(1);

    }
    sharePtr(sharePtr &sp):ptr(sp.ptr),pcount(&(++*sp.pcount)){}
    ~sharePtr()
    {
        
    }
    sharePtr& operator=(sharePtr &sp)
    {
        ptr=sp.ptr;
        pcount=&(++*sp.pcount);
    }
    T& operator*()
    {
        return *this->ptr;
    }
    T* operator->()
    {
        return this->ptr;
    }

    int user_count()
    {
        return *this->pcount;
    }

private:
    T* ptr;
    int *pcount;
};

class A
{
public:
    A(int a=0):a(a){}
    ~A(){}
    void print()
    {
        cout << a << endl;
    }
    int a;
};

void test_my_sharePtr()
{
    sharePtr<A> sp(new A());
    auto sp1=sp;
    cout << sp1.user_count() << endl;
}




int main()
{

    // test_share_simplecase();
    // test_localValue_lifetime();
    // test_my_sharePtr();
    C c1(100);
    C c2(c1);
    c2.print();


    return 0;
}





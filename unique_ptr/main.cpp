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


//实现unique_ptr
template<typename T>
struct uniquePtr
{
    uniquePtr(T* ptr = nullptr)
        : ptr(ptr)
    {
        
    }

    ~uniquePtr()
    {
        if(this->ptr != nullptr)
        {
            delete this->ptr;
            this->ptr = nullptr;
        }
    }

    uniquePtr(const uniquePtr& ptr4) = delete; // disable copying

    uniquePtr(uniquePtr&& ptr4) noexcept // move constructor
        : ptr(ptr4)
    {
        ptr4.ptr = nullptr;
    }

    uniquePtr& operator=(const uniquePtr& ptr4) = delete; // disable copy assignment

    uniquePtr& operator=(uniquePtr&& ptr4) noexcept // move assignment
    {
        if(this == &ptr4)
        {
            return *this;
        }

        delete this->ptr;
        this->ptr = ptr4.ptr;
        ptr4.ptr = nullptr;
        return *this;
    }

    T& operator*() const
    {
        return *this->ptr;
    }

    T* operator->() const
    {
        return this->ptr;
    }

    bool isNull() const
    {
        return this->ptr == nullptr;
    }

private:
    T* ptr;
};


int main()
{

    return 0;
}
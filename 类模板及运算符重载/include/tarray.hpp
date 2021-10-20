#ifndef TARRAY_HPP
#define TARRAY_HPP
#include <iostream>
// 类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到
// 将声明和实现写到同一个文件中，并更改后缀名为.hpp

template <class DataType>
class Array; //全局函数做友元函数必须要声明

template <class DataType>
std::ostream &operator<<(std::ostream &cout, const Array<DataType> &A); //全局函数做友元函数必须要声明

template <class DataType>
class Array
{
    //<>必不可少 ，表明此友元函数是函数模板 此模板使用的模板类型参数为当前
    // 模板类的类型参数class
    friend std::ostream &operator<<<>(std::ostream &cout, const Array<DataType> &A);

public:
    Array(const int &n);
    Array(const int n, DataType val);
    Array(const Array<DataType> &A);
    ~Array();

    void print();

    // 运算符重载
    //！！！！当函数传递的参数为对象时，参数传递选择“传值调用“时，生成临时对象会执行构造函数，销毁时会调用析构函数
    //！！！！所以要优先选择“引用传递“，来提高函数执行效率
    //！！！！传参数选择“引用传递“时，最好要加上const,因为如果一个传入的参数是一个临时变量，编译器认为临时变量没有修改意义回报错
    // 算术运算符
    Array<DataType> &operator=(const Array<DataType> &A);
    Array<DataType> operator+(const Array<DataType> &A);
    Array<DataType> operator-(const Array<DataType> &A);
    Array<DataType> &operator++();
    Array<DataType> operator++(int);        //后置++
    // 关系运算符
    bool operator==(const Array<DataType> &A);
    bool operator!=(const Array<DataType> &A);
    // 特殊运算符
    DataType &operator[](int index);

public:
    int size;
    DataType *p;
};

//给定大小构造
template <class DataType>
Array<DataType>::Array(const int &n)
{
    this->size = n;
    this->p = new DataType[n];
    for (int i = 0; i < this->size; i++)
    {
        this->p[i] = DataType(0);
    }
}

//给定大小和初始值构造
template <class DataType>
Array<DataType>::Array(const int n, DataType val)
{
    this->size = n;
    this->p = new DataType[n];
    for (int i = 0; i < this->size; i++)
    {
        this->p[i] = val;
    }
}
//拷贝构造
template <class DataType>
Array<DataType>::Array(const Array<DataType> &A)
{
    if (this != &A)
    {
        size = A.size;
        p = new DataType[size];
        for (int i = 0; i < size; i++)
            p[i] = A.p[i];
    }
}
// 析构函数
template <class DataType>
Array<DataType>::~Array()
{
    if (p != NULL)
    {
        delete[] p;
    }
}

// 重载 <<
template <class DataType>
std::ostream &operator<<(std::ostream &cout, const Array<DataType> &A)
{
    cout << "[";
    for (int i = 0; i < A.size - 1; i++)
    {
        cout << A.p[i] << ",";
    }
    cout << A.p[A.size - 1] << "]";
    return cout;
}

// 重载 =
template <class DataType>
Array<DataType> &Array<DataType>::operator=(const Array<DataType> &A)
{
    // !!!!返回值必须要是引用。若返回的不是引用，实际赋值过程(A=B)，返回的值其实是一个副本，A指向这个副本
    // 但是默认的拷贝构造为浅拷贝，A只是指向这个副本，但是这个副本在函数调用结束后消亡，导致A指向地址错误

    if (this != &A)
    {
        if (size != A.size)
        {
            delete[] p;
            size = A.size;
            p = new DataType[size];
        }
        for (int i = 0; i < A.size; i++)
        {
            p[i] = A.p[i];
        }
    }
    return *this;
    // return *this返回的是当前对象的克隆或者本身（若返回类型为A， 则是克隆， 若返回类型为A&， 则是本身 ）
    // return *this 返回当前对象的引用,返回类型为引用时，不能使用return this
}
// 重载 +
template <class DataType>
Array<DataType> Array<DataType>::operator+(const Array<DataType> &A)
{
    // C=A+B实际运行过程： 返回一个临时变量，临时变量传给等号重载函数，此时“=重载函数“传入的参数必须为const,
    // 因为返回一个临时变量，修改一个临时变量是毫无意义的，据此，c++编译器加入了临时变量不能作为非const引用的这个语义限制。
    //
    Array<DataType> temp(A.size);
    for (int i = 0; i < size; i++)
    {
        temp.p[i] = p[i] + A.p[i];
    }
    return temp;
}

// 重载 -
template <class DataType>
Array<DataType> Array<DataType>::operator-(const Array<DataType> &A)
{
    Array<DataType> temp(A.size);
    for (int i = 0; i < size; i++)
    {
        temp.p[i] = p[i] - A.p[i];
    }
    return temp;
}
// 重载 前置++
// ++A,先++,再返回A
template <class DataType>
Array<DataType> &Array<DataType>::operator++()
{
    for (int i = 0; i < size; i++)
    {
        ++p[i];
    }
    return *this;
}
// 重载 后置++
// A++,先返回A，再++
template <class DataType>
Array<DataType> Array<DataType>::operator++(int) //规定int 区分前置++
{
    Array<DataType> temp(*this);
    for (int i = 0; i < size; i++)
    {
        p[i]++;
    }
    return temp;
    // return *this返回的是当前对象的克隆或者本身（若返回类型为A， 则是克隆， 若返回类型为A&， 则是本身 ）
    // 不返回引用 无法使用 cout << A++ << endl,因为返回的是副本的指针
    // !!!!!!要想可以使用，要 重载<<时的传参必须要加上const
    // 因为返回一个临时变量，修改一个临时变量是毫无意义的，据此，c++编译器加入了临时变量不能作为非const引用的这个语义限制。
}

// 重载 ==
template <class DataType>
bool Array<DataType>::operator==(const Array<DataType> &A)
{
    if (size != A.size)
        return false;
    else
    {
        for (int i = 0; i < size; i++)
        {
            if (p[i] != A.p[i])
                return false;
        }
        return true;
    }
}

// 重载 !=
template <class DataType>
bool Array<DataType>::operator!=(const Array<DataType> &A)
{
    if (size != A.size)
        return true;
    else
    {
        for (int i = 0; i < size; i++)
        {
            if (p[i] != A.p[i])
                return true;
        }
        return false;
    }
}

// 重载 []
template <class DataType>
DataType &Array<DataType>::operator[](int index)
{
    return this->p[index];
}
#endif
#include <iostream>

using namespace std;

// std::move并不能移动任何东西，它唯一的功能是将一个左值强制转化为右值引用，
// 继而可以通过右值引用使用该值，以用于移动语义。
// 从实现上讲，std::move基本等同于一个类型转换：static_cast<T&&>(lvalue);
// std::move是将对象的状态或者所有权从一个对象转移到另一个对象，只是转移，
// 没有内存的搬迁或者内存拷贝所以可以提高利用效率,改善性能.。


// 左值(lvalue)和右值(rvalue)：区别在于变量是可寻址的（addressable）对于每一个变量都有两个值与其相联：
// 1).它的数据值，存储在某个内存地址中。
// 2).它的地址值——即存储数据值的那块内存的地址。


// 引用折叠规则
// 经过类型推导的 T&& 类型，相比右值引用(&&)会发生类型变化，这种变化被称为引用折叠或崩塌。规则：
//     所有的右值引用叠加到右值引用上仍然还是一个右值引用；
//     所有的其他引用类型之间的叠加都将变成左值引用。
// 总之是，所有的右值引用叠加到右值引用上仍然是一个右值引用，其他引用折叠都是左值引用。
// T& &、T& &&和T&& & 都折叠成类型 T& 
// T&& &&折叠成 T&&






//a与b指向同一块内存
void test_int_move()
{
    int a =5;
    int &&b = std::move(a);
    
    cout << a << endl;
    cout << b << endl;
    cout << &a << endl;
    cout << &b << endl;  
}


void test_str_move()
{
    string s{"abcdefg"};
    string m = move(s);
    cout << "s: " << s <<endl;
    cout << "m: " << m <<endl;
}

int main()
{
    test_str_move();
    return 0;
}
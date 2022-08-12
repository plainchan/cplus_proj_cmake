#include <iostream>

using namespace std;

// std::move并不能移动任何东西，它唯一的功能是将一个左值强制转化为右值引用，
// 继而可以通过右值引用使用该值，以用于移动语义。
// 从实现上讲，std::move基本等同于一个类型转换：static_cast<T&&>(lvalue);
// std::move是将对象的状态或者所有权从一个对象转移到另一个对象，只是转移，
// 没有内存的搬迁或者内存拷贝所以可以提高利用效率,改善性能.。

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
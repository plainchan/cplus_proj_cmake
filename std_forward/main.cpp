#include <iostream>

using namespace std;

// std::forward通常是用于完美转发的，它会将输入的参数原封不动地传递到下一个函数中，这个“原封不动”指的是，如果输入的参数是左值，那么传递给下一个函数的参数的也是左值；如果输入的参数是右值，那么传递给下一个函数的参数的也是右值。一个经典的完美转发的场景是：



// void _print(int t)
// {
//     cout << t << ",type 1" << endl;
// }
void _print(int &t)
{
    cout << t << ",type 2" << endl;
}
void _print(int &&t)
{
    cout << t << ",type 3" << endl;
}

// 当我们将一个右值引用传入函数时，他在实参中有了命名，所以继续往下传或者调用其他函数时，
// 根据C++ 标准的定义，这个参数变成了一个左值。那么他永远不会调用接下来函数的右值版本，这可能在一些情况下造成拷贝
template<class T>
void print(T&& t)
{
    // 不使用std::forward
    _print(t);


    // 使用std::forward
    _print(std::forward<T>(t));
}

int main()
{
    int x =100;
    int &y = x;
    int &&z = 500;
    print(std::forward<int>(z));
    print(501);
    return 0;
}
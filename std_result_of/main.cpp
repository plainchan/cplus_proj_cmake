#include <iostream>

using namespace std;


// 引用折叠
// 模板传入的参数可能是个左值，也可能是个右值
// void F(int x)
// {
//     cout << "type 1" << endl;
// }  
template<typename T>
void F(T&& t)
{
    cout << "type 2" << endl;
}  
void test_cite()
{
    F(10);  // F(10) 传入左值   type 1
    
    int x = 10;
    F(x);  // 传入左值，发生引用折叠，实际是个左值  type 1

    F(std::forward<int>(x));
}



// 引用折叠规则
// 经过类型推导的 T&& 类型，相比右值引用(&&)会发生类型变化，这种变化被称为引用折叠或崩塌。
// 规则：
//     所有的右值引用叠加到右值引用上仍然还是一个右值引用，T&& &&折叠成 T&&；
//     所有的其他引用类型之间的叠加都将变成左值引用，T& &、T& &&和T&& & 都折叠成类型 T&。

// std::forward通常是用于完美转发的，它会将输入的参数原封不动地传递到下一个函数中，这个“原封不动”指的是，
// 如果输入的参数是左值，那么传递给下一个函数的参数的也是左值；如果输入的参数是右值，那么传递给下一个函数的参数的也是右值。

int main()
{

    test_cite();
    return 0;
}
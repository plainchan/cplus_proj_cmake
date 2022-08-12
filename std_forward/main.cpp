#include <iostream>

using namespace std;

// std::forward通常是用于完美转发的，它会将输入的参数原封不动地传递到下一个函数中，这个“原封不动”指的是，如果输入的参数是左值，那么传递给下一个函数的参数的也是左值；如果输入的参数是右值，那么传递给下一个函数的参数的也是右值。一个经典的完美转发的场景是：

int main()
{


    cout << "Hello World" << endl;
    return 0;
}
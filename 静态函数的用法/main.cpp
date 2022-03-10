#include <iostream>

using namespace std;

// 静态函数又称为内部函数。
// 在C/C++中，定义的函数默认都是全局的(相对于多个文件的源程序)。
// 而在函数的前面加上static关键字可以改变函数的作用域，
// 即将函数的作用域限定在含有此函数的定义所在的文件，在其他文件中不可以使用此函数。


int main()
{


    cout << "Hello World" << endl;
    return 0;
}
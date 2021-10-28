#include <iostream>
#include <typeinfo>
using namespace std;

/*
* define 用法
*/
#define PI 3.14           //文本替换
#define f(x, y) (x) * (y) //错误  #define f(x, y)  x*y

/*
* typedef 用法
* define 在预处理过程完成，typedef 在编译阶段完成，
* 官方定义:Typedef does not work like typedef [type] [new name]. 
*         The [new name] part does not always come at the end.
*         You should look at it this way: 
*         if [some declaration] declares a variable, typedef [same declaration] would define a type.
*翻译：任何声明变量的语句前面加上typedef之后，原来是变量的都变成一种类型。不管这个声明中的标识符号出现在中间还是最后.
*/

//!!!! 不是 typedef [type] [new_name]
//!!!! 而是long int64,声明一个long类型的变量 int64
//!!!! 前面加上typedef 将“变量名“定义成为一种类型(它所隐含的数据类型)
typedef long int64;

// int P[5],变量名为P，数据类型：大小为5的整数型数组
// typedef int P[5]，将变量名“P“定义为“大小为5的整数型数组“
// 注意变量名是P，而不是P[5]
typedef int P[5];

// 定义一个名为function,参数为空，返回类型为int的函数类型
typedef int function();

int main()
{
    cout << "***********define***********" << endl;
    cout << "宏替换  PI= " << PI << endl;

    int res = f(3 + 1, 2);
    cout << "f(3 + 1, 2) =" << res << endl; //错误   理想的应是(3+1)*2，但实际是3+1*2

    cout << "***********typedef***********" << endl;

    // typedef  整数类型
    // if (typeid(long).name() == typeid(int64).name())
    //     cout << "long == int64 size =" << sizeof(int64) << endl;
    if (is_same_v<long, int64>)
        cout << "long == int64 size =" << sizeof(int64) << endl;

    int64 a = 10;
    int64(b) = 10;
    cout << "a= " << a << ";"
         << "b= " << b << endl;

    // typedef 数组类型
    P A = {1, 2, 3, 4, 5};
    P(B) = {1, 2, 3, 4, 5}; //等价于 P B={1, 2, 3, 4, 5}
    P(C);
    C[0] = 1;
    C[1] = 1;
    C[2] = 1;
    C[3] = 1;
    C[4] = 1;
    cout << "A: ";
    for (auto i : C)
        cout << i << " ";
    cout << endl;

    // typedef 函数类型
    function(print); //等价于 声明 int print()
}

// typedef int P();
// typedef int Q();
// class X {
//     static P(Q); // 等价于`static int Q()`, Q在此作用域中不再是一个类型
//     static Q(P); // 等价于`static int Q(int ())`, 定义了一个名为Q的function
// };
// static P(Q);  等价于`static int Q()`
// 此时调用Q(),其实代表返回的int类型数据，Q不再是一个类型，而是一个整数
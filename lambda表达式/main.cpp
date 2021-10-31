#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
* ！！！！lambda 表达式创建的是对象！！！！
* C++ 11 中的 Lambda 表达式用于定义并创建匿名的函数对象，以简化编程工作。
* [ capture ] ( params ) opt -> ret { body; }
* carpture是捕获列表(非params的外部变量)，params是参数，opt是选项，ret则是返回值的类型，body则是函数的具体实现。
*  [] :表示不捕获任何变量
*  [=]：表示按值捕获变量
*  [&]：表示按引用捕获变量
*  [this]：值传递捕获当前的this
*/

// lambda结合容器Vector创建匿名函数
void lambda_calcuSum()
{
    vector<int> v;
    int sum = 0;
    for (int i = 0; i < 100; i++)
    {
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), [&](int x){ sum += x; });
    cout << "sum = " << sum << endl;
}

//lambda 创建非匿名函数
auto print = [](vector<int> &v)
{
    cout << "[";
    for (auto i : v)
        cout << i << " ";
    cout << "]" << endl;;
};
int main()
{
    //lambda 表达式创建的是对象
    auto lambda = []{}; 
    cout << "is object: " << is_object<decltype(lambda)>::value << endl; 
    cout << "is function: " << is_function<decltype(lambda)>::value << endl;
    
    // lambda_calcuSum();

    vector<int> v1;
    for (int i = 0; i < 20; i++)
    {
        v1.emplace_back(i);
    }
    print(v1);
    return 0;
}

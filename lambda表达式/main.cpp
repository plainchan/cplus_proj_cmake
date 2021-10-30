#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
*
* C++ 11 中的 Lambda 表达式用于定义并创建匿名的函数对象，以简化编程工作。
* [外部变量访问方式说明符] (参数表) -> 返回值类型  {语句块}
*/
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
int main()
{
    lambda_calcuSum();
    cout << "Hello World" << endl;
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

// decltype 的主要用途大概就在于声明那些返回值型别依赖于形参型别的函数模板。


//返回值型别尾序  C++11
// template<typename Container>
// auto  getFirstValue(Container &c) ->decltype(c[0])
// {
//     return c[0];
// }

// C++14  不需要尾序写法
template<typename Container>
auto  getFirstValue(Container &c) 
{
    return c[0];
}
//最优化版本 C++14 万能引用+decltype(auto)
template<typename Container>
decltype(auto)
getFirstValue(Container &&c) 
{
    return c[0];
}

int main()
{

    vector<int> a{100,2,3};
    cout << getFirstValue(a) << endl;
}
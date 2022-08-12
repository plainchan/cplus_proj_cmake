#include <iostream>

using namespace std;

//模板参数长度
template<typename...Args>
void paramsLength(Args...args)
{
    std::cout << sizeof...(args) << std::endl ;
}

// 展开可变模版参数

// 1.递归展开
// 递归终止函数
void recursionPrint()
{
    std::cout << std::endl ;
}
// 展开函数
template<typename T,typename...Args>
void recursionPrint(T first,Args...args)
{
    std::cout << first << " ";
    recursionPrint(args...);
}
template<typename T>
T recursionSum(T t)
{
    return t;
}
// 展开函数
template<typename T,typename...Args>
T recursionSum(T first,Args...args)
{
    return first+recursionSum(args...);
}


int main()
{
    // cout << recursionSum(1,2,3,4) << endl;;

	return 0;
}
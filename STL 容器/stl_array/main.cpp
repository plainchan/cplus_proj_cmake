#include <iostream>
#include <array>
using namespace std;

/*
* array 固定大小数组，初始化确定大小后不可更改
*
*
*/

//传入参数时候使用auto自动类型,可以避免传入array容器参数时，要求指定大小
auto print = [](const auto &v)
{
    cout << "[";
    for (auto i : v)
        cout << i << " ";
    cout << "]" << endl;
};

int main()
{
    cout << "**********************构造*********************" << endl;
    array<int, 5> a{1, 2, 3, 4, 5};
    array<int, 5> b(a);
    cout << "a = ";print(a);
    cout << "b = ";print(b);

    cout << "**********************访问 遍历*********************" << endl;
    cout << "a[0] = " << a[0] << endl;
    cout << "a.at(0) = " << a.at(0) << endl;
    cout << "a.front() = " << a.front() << endl;
    cout << "a.back() = " << a.back() << endl;
    
    // 返回指向作为元素存储工作的底层数组的指针。
    // 指针满足范围 [data(); data() + size()) 始终是合法范围，即使容器为空（该情况下 data() 不可解引用）。
    cout << "a.data() = " << a.data() << endl;

    cout << "[" ;
    for (array<int, 5>::const_iterator it = a.begin(); it != a.end()-1; it++)
    {
        cout << *it << " ";
    }
    cout << a.back() << "]" << endl;

    cout << "**********************大小 交换*********************" << endl;
    array<int, 5> c{5,4,3,2,1};
    cout << "a = ";print(a);
    cout << "c = ";print(c);
    cout << "a.size() = " << a.size() << endl;
    a.swap(c);                               //只能交换同等大小的
    cout << "a = ";print(a);
    cout << "c = ";print(c);
    a.fill(1);
    cout << "a = ";print(a);


    return 0;
}
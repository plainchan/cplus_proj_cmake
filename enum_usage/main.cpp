#include <iostream>
using namespace std;

/*
 * 定义enum类型后，可以直接用里面的值
 * 不同类型里面的名称不能重复
 * enum 相当于#define 的集合
 */
enum week
{
    Mon = 1,
    Tue,
    Wed,
    Thu,
    Fri,
    Sat,
    Sun
}; //Monday、Tuesday等为符号常量，通常称之为枚举量
enum Month
{
    Jan = 1,
    Feb,
    Mar,
    Apr,
    May,
    Jun,
    Jul,
};

#define PI 3.14
int main()
{
    cout << Jun << endl; //直接用枚举中类型值

    Month M;
    M = May;
    cout << "M=" << M << endl;

    auto Sun = false;
    cout << "Sun=" << Sun << endl; //错误
    // auto PI = 5;
    cout << "PI=" << PI << endl; //错误

    //不同类型的枚举不能相互比较，即使编译器可以通过语法检查
    //    if (Mon == Jan)
    //        cout << "same" << endl;

    return 0;
}
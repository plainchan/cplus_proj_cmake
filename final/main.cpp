#include <iostream>
using namespace std;

//禁用继承
//禁用重写

struct Base
{
    virtual void foo();
};
 
struct A : Base
{
    void foo() final; // Base::foo 被覆盖而 A::foo 是最终覆盖函数
    void bar() final; // 错误：bar 非虚，因此它不能是 final 的
};
 
struct B final : A // struct B 为 final
{
    void foo() override; // 错误：foo 不能被覆盖，因为它在 A 中是 final 的
};
 
struct C : B{}; // 错误：B 是 final 的


int main()
{

    return 0;
}
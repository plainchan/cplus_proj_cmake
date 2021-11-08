#include "example.hpp"

using namespace std;

int main()
{




















    {
        // 禁止
        // 任何条件下都要禁止重新定义继承而来的非虚函数。
        special_case::A a;
        special_case::B b;
        a.foo();
        b.foo();
        b.A::foo();
    }
    return 0;
}
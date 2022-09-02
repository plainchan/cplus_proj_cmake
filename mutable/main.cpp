#include <iostream>
using namespace std;

int main()
{
    class A
    {
    public:
        void test_mutable() const
        {
            cout << ++num << endl; 
        }
        mutable int num=0;   //突破const限制，让编译器就明白：
        // 这个变量不算对象内部状态，修改它并不影响const语义，所以就不需要禁止const函数修改它了。
    };

    A a;
    a.test_mutable();

    return 0;
}
#include <iostream>
#include <optional>
using namespace std;

//类模板 std::optional 管理一个可选的容纳值，既可以存在也可以不存在的值。

int main()
{
    {
        cout << "----------构造------------" << endl;
        optional<int> op = 0;
        optional<int> op1 = nullopt;
        optional<string> op2 = "Hello World"s; //数据类型为类

        cout << "---------访问-------------" << endl;

        cout << "op = " << *op << endl;  //无条件访问op的value,尽管内部的value bool 标志设置为否

        //返回指向所含值的指针。
        cout << "op2 字符串大小" << op2->size() << endl; //通过->访问存放的数据类型为 类的 成员函数

        if (op.has_value())
        {
            cout << "op has value" << endl;
            cout << "op = " << op.value() << endl; //value() 如果没有值会抛出异常
        }

        int res = op1.value_or(-1); //如果存在值，则返回值，没有则返回给定值-1
        if (res == -1)
            cout << "op1 don't has value" << endl;
        else
            cout << "op1 has value,value = " << op.value() << endl;
    }

    {
        cout << "---------修改-------------" << endl;
        optional<int> op = 100;
        op.reset();
        if(op.has_value())
            cout << "op has value,op = " << op.value() << endl;
        else
            cout << *op << endl;

        op.emplace<int>(250);
        cout << "op = " << op.value() << endl;
    }

    return 0;
}
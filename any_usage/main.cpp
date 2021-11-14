#include <iostream>
#include <any>

using namespace std;

int main()
{
    
    any a = 100;
    //any_cast 对被容纳对象的类型安全访问
    cout << a.type().name() << ": " << any_cast<int>(a) << endl;


    //销毁对象
    a.reset();
    if(!a.has_value())
        cout << "a has no value" << endl;
    //更改
    a.emplace<int>(250);
    if(a.has_value())
        cout << "a has value,a = " << any_cast<int>(a) << endl;

    //make_any
    cout << "--------make_any-------" << endl;
    any H = make_any<string>("Hello World");
    cout << "H = " << any_cast<string&>(H) << endl;


    return 0;
}
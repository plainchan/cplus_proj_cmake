#include <iostream>
#include <variant>

using namespace std;

//先执行try块中的语句，如果执行的过程中没有异常拋出，
//跳过所有的catch语句，执行catch后面的语句

int main()
{
    try
    {
        int *p=new int;
        cout << *p << endl;
        delete p;

        cout << "-------- 构造--------" << endl;
        variant< int, float, char,string> var{"123"s};
        // var ="plaichn";
        cout << var.index() << endl;
        cout << get<float>(var) << endl;

    }
    catch(exception &e)
    {
        cout <<e.what() << endl;
        cout << "mother fucker " << endl;

    }
    cout << "hello world " << endl;
}


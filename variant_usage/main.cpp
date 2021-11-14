#include <iostream>
#include <variant>

using namespace std;

//需要在CMakeLists.txt设置c++ 17

//variant 根据赋值，根据已经提供的数据类型，自动判断属于哪一种

int main()
{
    try
    {
        cout << "-------------- 构造---------------" << endl;
        variant<int, float, char,string> var{"Hello world"};
        variant<double,int,char> valu;
        valu = 1.60;
        

        cout << "---------获取存储类型下标-----------" << endl;
        cout << var.index() << endl;

        cout << "-------------- 获取、更该存储数据---------------" << endl;
        cout << get<string>(var) << endl;  //没有此类型会抛出异常
        visit([](auto &v){cout << v << endl;},var);

        var.emplace<int>(2021);
        cout << get<int>(var) << endl;  
        visit([](auto &v){cout << v << endl;},var);
        
        
        return 0;
    }
    catch(exception &e)
    {
        cout << "------------异常-------------" << endl;
        cout <<e.what() << endl;
    }
}
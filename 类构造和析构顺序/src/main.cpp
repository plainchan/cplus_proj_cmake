#include "example.h"

using namespace std;

void test_inherit()
{

    cout << "----继承中的构造和析构顺序---" << endl;
    cout << "----Son继承Parent---" << endl;
    Son son;
}

void test_constructor_decl()
{
    cout << "----无继承关系但类的构造中声明新类---" << endl;
    cout << "----Person 构造函数中声明 Friend类---" << endl;
    Person man;
}

int main()
{
    test_inherit();

    test_constructor_decl();
    
    
    return 0;
}
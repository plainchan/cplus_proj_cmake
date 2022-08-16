#include <iostream>
#include <typeinfo>

using namespace std;

void test_dataTypeName()
{
    cout << typeid(int).name() << endl;
    cout << typeid(float).name() << endl;
}


int main()
{

    {
        test_dataTypeName();
    }

    return 0;
}
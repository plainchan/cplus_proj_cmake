#include "example.hpp"
using namespace std;



int main()
{
    Person P("plain",24);

    
    cout << P.name << endl;
    cout << P.age << endl;
    // cout << P.salary << endl;   //权限不够
    cout << P.getSalary() << endl;
    return 0;
}


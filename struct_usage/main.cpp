#include "example.hpp"
using namespace std;
#include <vector>


int main()
{
    {
        Person P("plain",24);

    
        cout << P.name << endl;
        cout << P.age << endl;
        // cout << P.salary << endl;   //ζιδΈε€
        cout << P.getSalary() << endl;
    }
    vector<int> a(10);
    a[0]=1;
    for(int i=0;i<10-1;)
        a[++i]=a[i];
    for(int i=0;i<10;i++)
        cout << a[i] << " ";

    return 0;
}


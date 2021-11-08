#include <iostream>
#include <exception>
using namespace std;

int main()
{
    int a = 0;
    while (true)
    {
        cin >> a;
        try
        {
            if (a == 0)
                throw "one erro";
            else
                cout << "a = " << a << endl;
        }
        catch (char const*str)
        {
            cout << "Don't input 0" << endl;
        }
    }
    return 0;
}
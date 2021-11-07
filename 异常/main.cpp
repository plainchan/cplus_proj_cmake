#include <iostream>
#include <exception>
using namespace std;

int main()
{
    int a = 0;
    while (true)
    {
        cin >> a;
        cout << a << endl;
        try
        {
            if (a == 1)
                throw "one erro";
            else
                cout << "a = " << a << endl;
        }
        catch (char const*str)
        {
            cout << "Don't input 1" << endl;
            // continue;
        }
    }
    return 0;
}
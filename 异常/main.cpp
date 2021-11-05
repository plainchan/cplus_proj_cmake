#include <iostream>

using namespace std;

int main()
{

    try
    {
        int a = 5 / 1;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    cout << "Hello World" << endl;
    return 0;
}
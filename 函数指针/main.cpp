#include <iostream>
using namespace std;

void print(int n, int m)
{
    cout << "n";
}

// void foo(int i)
// {
//     cout << "this is normal function" << endl;
// }
void foo(int *i)
{
    cout << "this is ptr function" << endl;
}

int main()
{
    foo(NULL);
    cout << "hello world" << endl;
    return 0;
}
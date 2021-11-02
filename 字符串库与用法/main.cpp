#include <iostream>

using namespace std;

/*
*   string封装了char，管理字符串，是char型的一个容器(typedef basic_string<char> string)
*   
*/

int main()
{
    cout << "**************** string 与char str[] *************" << endl;
    string str="Hello World";
    char cstr[]="Hello World";
    return 0;
}
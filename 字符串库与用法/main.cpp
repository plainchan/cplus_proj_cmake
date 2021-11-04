#include <iostream>
#include <vector>
using namespace std;

/*
*   string封装了char，管理字符串，是char型的一个容器(typedef basic_string<char> string)
*   
*/

int main()
{
    {
        cout << "**************** 构造 *************" << endl;
        // string str{"Hello World"};
        string str("Hello World");
        string str1 = "Hello World";
        string str2(str1);
        string str3("Hello", 5);  //声明空间大小

        cout << "str: " << str << endl;
        cout << "str1: " << str1 << endl;
        cout << "str2: " << str2 << endl;
        cout << "str3: " << str3 << endl;
    }

    {
        cout << "**************** string 与char str[] *************" << endl;
        string str("Hello World");
        char cstr[] = "Hello World";   //会自动在字符串后面添加结束符\0,占用一个字节
        char cstr1[] = {'H','e','l','l','o',' ','W','o','r','l','d'};//不会自动在字符串后面添加结束符\0
        cout << "sizeof(cstr) = " << sizeof(cstr) << endl;  
        cout << "str.capacity = " << str.capacity() << endl; //通常会比字符串的实际容量大
        char *p =cstr1;
        while (*p)
        {
            cout << *p++;
        }  //没有停止符会溢出
        cout << endl;
        

    }

    {
        cout << "**************** 访问 *************" << endl;
    }
    return 0;
}
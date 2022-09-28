#include <iostream>
#include <cstring>
using namespace std;


int main()
{
    //p1是一个指针，存放在栈区,"Hello World"是一个常量，位于常量区,
    char *p1 = (char*)"Hello World";   //指针指向的地方不可修改
    char p2[] = "Hello World";     //位于位于栈上
    char *p3 = new char[12];      //位于位于堆上
    strcpy(p3,"Hello World");

    // *p1='h';    //错误，不可修改
    *p2='\0';
    *p3='\0';
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;

    delete[] p3;

    return 0;
}
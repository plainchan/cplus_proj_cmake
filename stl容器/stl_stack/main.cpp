#include <iostream>
#include <stack>
using namespace std;
/*
* stack是一种先进后出(First In Last Out,FILO)的数据结构，它只有一个出口
*/
int main()
{
    // 构造
    stack<int> s;
    for (int i = 0; i < 10; i++)
        s.push(i);
    stack<int> s1(s);
    cout << "栈顶元素：" << s.top() << endl;
    cout << "s size = " << s.size() <<endl;

    //出入栈
    s.push(99);
    cout << "s.push(99) 栈顶元素：" << s.top() << endl;
    cout << "s size = " << s.size() <<endl;
    s.pop();
    cout << "s.pop() 栈顶元素：" << s.top() << endl;
    cout << "s size = " << s.size() <<endl;

    return 0;
}
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
/*
* double-ended queue, 类似于vector的构造和内置方法函数,但两端都可以增删
* deque没有容量的概念
* vector对于头部的插入删除效率低，数据量越大，效率越低
* deque相对而言，对头部的插入删除速度回比vector快
* vector访问元素时的速度会比deque快,这和两者内部实现有关
*/
void print(deque<int> &d)
{
    for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
int main()
{
    cout << "------构造------" << endl;
    deque<int> d;
    for (int i = 0; i < 10; i++)
        d.push_back(i);
    deque<int> d1(d);
    deque<int> d2(10, 1);
    deque<int> d3(d.begin(), d.end());
    cout << "d: ";
    print(d);
    cout << "d1: ";
    print(d1);
    cout << "d2: ";
    print(d2);
    cout << "d3: ";
    print(d3);

    cout << "------赋值 访问 ------" << endl;
    d.assign(15, 0);
    d1.assign(15, 1);
    cout << "d: ";
    print(d);
    cout << "d1: ";
    print(d1);
    d[0] = 10;
    cout << "修改d[0] d: ";
    print(d);
    cout << "d.at(0) = " << d.at(0) << endl;
    cout << "d[0] = " << d[0] << endl;
    cout << "d.front = " << d.front() << endl;
    cout << "d.back = " << d.back() << endl;

    cout << "------增删 大小------" << endl;
    cout << "d3: ";
    print(d3);
    cout << "d3 size = " << d3.size() << endl;
    d3.push_back(10);
    cout << "后端增加元素10:";
    print(d3);
    cout << "d3 size = " << d3.size() << endl;
    d3.push_front(-1);
    cout << "前端增加元素-1:";
    print(d3);
    cout << "d3 size = " << d3.size() << endl;
    d3.pop_back();
    cout << "后端删除元素10:";
    print(d3);
    cout << "d3 size = " << d3.size() << endl;
    d3.pop_front();
    cout << "前端删除元素-1:";
    print(d3);
    cout << "d3 size = " << d3.size() << endl;

    d3.resize(15, 11);
    cout << "d3 resize>origin: " << endl;
    print(d3);
    cout << "d3 size = " << d3.size() << endl;

    cout << "------插入 清空------" << endl;
    d3.insert(d3.begin(), -1);
    cout << "前端插入元素-1:";
    print(d3);
    // d3.erase(d3.begin(), d3.end());
    d3.clear();
    if (d3.empty())
        cout << "d3 is empty" << endl;

    cout << "------ 排序------" << endl;
    print(d);
    sort(d.begin(),d.end());
    print(d);

    return 0;
}
#include <iostream>
#include <list>
using namespace std;

/*
* 链表的组成：链表由一系列结点组成
* 结点的组成：一个是存储数据元素的数据域，另一个是存储下一个结点地址的指针域
* 指针域包括：前一个元素地址，后一个元素地址。STL中的链表是一个双向循环链表
* List有一个重要的性质，插入操作和删除操作都不会造成原有list迭代器的失效，这在vector是不成立的。
* 和deque有类似的构造和成员函数，只是list内存空间不连续,而deque内部采用分段连续的内存空间来存储元素
*/

void print(const list<int> &l)
{
    for (list<int>::const_iterator it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
int main()
{
    cout << "-------构造--------" << endl;
    list<int> l;
    for(int i=0;i<10;i++)
        l.push_back(i);
    list<int> l1(l);
    list<int> l2(l.begin(),l.end());
    list<int> l3(10,1);
    cout << "l:";print(l);
    cout << "l1:";print(l1);
    cout << "l2:";print(l2);
    cout << "l3:";print(l3);


    return 0;
}
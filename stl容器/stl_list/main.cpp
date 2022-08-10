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
    list<int> l4{1,2,3,4,5,6,7,8,9};
    cout << "l:";print(l);
    cout << "l1:";print(l1);
    cout << "l2:";print(l2);
    cout << "l3:";print(l3);
    cout << "l4:";print(l4);

    cout << "-------赋值---交换-----" << endl;
    l.assign(10,1);
    cout << "l.assign(10,1) l:";print(l);  //不支持 l[]访问存取
    l.swap(l1);
    cout << "l.swap l:";print(l); 
    cout << "l1:";print(l1);
    l1= l;
    cout << "l1= l l1:";print(l1); 

    cout << "-------增删---访问--清空------" << endl;
    l.push_back(10);
    cout << "l.push_back(10) l:";print(l); 
    l.push_front(-1);
    cout << "l.push_front(-1) l:";print(l);
    l.pop_back();
    cout << "l.pop_back() l:";print(l);
    l.pop_front();
    cout << "l.pop_front() l:";print(l);
    cout << "l第一个元素 = " << l.front() << endl;
    cout << "l最后一个元素 = " << l.back() << endl;
    l.insert(l.begin(), -1);
    l.insert(l.end(), 10);
    cout << "l.insert ";print(l);
    l.emplace(l.begin(), -2);
    l.emplace(l.end(), 11);
    cout << "l.emplace 更高效 ";print(l);
    l.remove(11);
    cout << "l.remove(11) ";print(l);
    l.erase(l.begin());
    cout << "l.erase ";print(l);
    l.clear();
    cout << "清空";print(l);

    cout << "-------反转-排序------" << endl;
    cout << "l1:";print(l1);
    l1.reverse();
    cout << "l1.reverse:";print(l1);
    l1.sort();
    cout << "排序l1:";print(l1);



    return 0;
}
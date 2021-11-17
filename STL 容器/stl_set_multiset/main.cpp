#include <iostream>
#include <set>
using namespace std;

/*
* set/multiset属于关联式容器，底层结构是用二叉树实现。
* 所有元素都会在插入时自动被排序
*
* set不可以插入重复数据，而multiset可以
* set插入数据的同时会返回插入结果，表示插入是否成功
* multiset不会检测数据，因此可以插入重复数据
*/

void print(const set<int> &s)
{
    for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
void print(const multiset<int> &s)
{
    for (multiset<int>::const_iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    cout << "----------构造---------" << endl;
    set<int> s{3,9,1,0,4,2,6,7,8,5};   //会对插入元素自动排序
    set<int> s1;
    for(int i=0;i<10;i++)
        s1.emplace(i);
    set<int> s2(s1);
    set<int> s3(s1.begin(),s1.end());
    set<int> s4 = s3;
    cout << "s:";print(s);
    cout << "s1:";print(s1);
    cout << "s2:";print(s2);
    cout << "s3:";print(s3);
    cout << "s4:";print(s4);

    multiset<int> ms{1,4,2,0,5,8,3,4,0,0,3,9,1,0,4,2,6,7,8,5};
    cout << "multiset ms:";print(ms);

    cout << "----------插入--删除-------" << endl;
    cout << "s:";print(s);
    s.insert(10);
    s.emplace(11);  //更高效
    cout << "insert && emplace :";print(s);
    s.erase(s.begin());
    cout << "erase :";print(s);

    //插入返回的是 std::pair<iterator, bool>
    pair<set<int>::iterator,bool> res = s.emplace(12);
    if(res.second)
        cout << "插入成功" << endl;
    else
        cout << "插入失败" << endl;



    cout << "----------查找--统计-------" << endl;
    cout << "s:";print(s);
    cout << "ms:";print(ms);
    cout << "find(1) :" << *s.find(5) << endl;
    cout << "ms元素0的个数:" << ms.count(8) <<endl;


    return 0;
}
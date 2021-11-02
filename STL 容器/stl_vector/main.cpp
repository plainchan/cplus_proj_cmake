#include <iostream>
#include <vector>
using namespace std;

/*
*  vector 类似数组，可以迭代遍历
*  可以动态扩展大小，并不是在原空间之后续接新空间
*  而是找更大的内存空间，然后将原数据拷贝新空间，释放原空间
*/
void print(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    // 构造
    vector<int> a;
    for (int i = 0; i < 10; i++)
        a.push_back(i);
    vector<int> b(10, 1);              //构造10个元素为1的vector
    vector<int> c(a);                  //拷贝构造
    vector<int> d(a.begin(), a.end()); //拷贝构造

    cout << "-------构造vector-------" << endl;
    cout << "a = ";print(a);
    cout << "b = ";print(b);
    cout << "c = ";print(c);
    cout << "d = ";print(d);


    cout << "------赋值 容量 大小 resize------- " << endl;
    b.assign(11,1);
    cout << "b = ";print(b);
    cout << "b capacity = " << b.capacity() <<endl;
    cout << "b size = " << b.size() <<endl;
    cout << "b capacity >= size " << endl;
    b.resize(10);
    cout << "resize<origin b = ";print(b);
    b.resize(15);
    cout << "resize>origin b = ";print(b);
    b.resize(20,2);
    cout << "指定值 resize>origin b = ";print(b);
    
 
    cout << "-------插入 删除 清空 空判断------ " << endl;
    a.push_back(10);
    cout << "尾部插入一个数据 a = ";print(a);
    a.pop_back();
    cout << "尾部删除一个数据 a = ";print(a);
    a.insert(a.begin(),100);
    cout << "开始位置插入一个数据 a = ";print(a);
    a.insert(a.begin(),5,5);
    cout << "开始位置插入n个数据 a = ";print(a);
    a.erase(a.begin());
    cout << "开始位置删除一个数据 a = ";print(a);
    // a.erase(a.begin(),a.end());
    a.clear();
    cout << "清空 a = ";print(a);
    if(a.empty())
        cout << "a is empty" << endl;


    cout << "-------索引------ " << endl;
    cout << "c = ";print(c);
    cout << "c.at(0)  c的第1个数据= " << c.at(0) << endl;
    cout << "c.font() c的第1个数据= " << c.front() << endl;
    cout << "c.back() c的最后1个数据= " << c.back() << endl;
    cout << "c的第2个数据= " << c[1] << endl;

    cout << "-------容器互换------ " << endl;
    a.assign(10,1);
    b.assign(10,2);
    cout << "a = ";print(a);
    cout << "b = ";print(b);
    cout << "swap a<->b" << endl;
    a.swap(b);
    cout << "a = ";print(a);
    cout << "b = ";print(b);
    
    // 减少vector在动态扩展容量时的扩展次数
    // 容器预留len个元素长度，预留位置不初始化，元素不可访问。
    cout << "-------预留空间------ " << endl;
    vector<int> v;
    v.reserve(100);
    v.emplace_back(100);
    print(v);


    cout << "*************容器指针*******************" << endl;
    vector<int> *vpoint = new vector<int>(20);
    cout << "vpoint指向的vector容器大小为" << vpoint->size() << endl;
    // for()


    return 0;
}
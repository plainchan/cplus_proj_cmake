#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

/***********************************************
*                常用算法Algorithm
* 1.generate(v.begin(),v.end(),generator)  使用生成器初始化容器
* 2.for_each()                             遍历容器
* 3.transform()                            搬运一个容器到另一个容器
* 4.find && find_if                        查找元素，返回元素位置迭代器
* 5.adjacent_ﬁnd()                         查找相邻重复元素,返回相邻元素的第一个位置的迭代器,i没有则返回第一个元素位置
* 6.count                                  统计元素出现次数
* 7.count_if                               按条件统计元素出现次数
* 8.binary_search                          查找指定的元素，查到 返回true 否则false,在无序序列中不可用
*
*
*
************************************************/
auto print = [](vector<int> &V)
{
    cout << "[";
    for (auto i : V)
        cout << i << " ";
    cout << "]" << endl;
};
int main()
{
    vector<int> v(10), v1(10);

    generate(v.begin(), v.end(), rand); //生成器初始化容器
    generate(v1.begin(), v1.end(), []() -> int
             {
                 static int x = 0;
                 return x++;
             });

    print(v);
    print(v1);

    transform(v1.begin(), v1.end(), v.begin(), [](int x) -> int
              { return x; });

    print(v);
    print(v1);

    auto it = find(v.begin(), v.end(), 5);
    cout << *it << endl;

    it = find_if(v.begin(), v.end(), [](int x) -> bool
                 {
                     if (x > 5)
                         return true;
                     else
                         return false;
                 });
    cout << *it << endl;

    v.emplace_back(2);
    v.emplace_back(2);
    print(v);
    it = adjacent_find(v.begin(), v.end());
    cout << *it << endl;

    cout << "2元素个数" << count(v.begin(), v.end(), 2) << endl;
    cout << "大于2的元素个数" << count_if(v.begin(), v.end(), [](int x) -> bool
                                          {
                                              if (x > 2)
                                                  return true;
                                              else
                                                  return false;
                                          })
         << endl;
    print(v1);
    if (binary_search(v1.begin(), v1.end(), 2))
        cout << "容器有元素2" << endl;

    //洗牌
    random_shuffle(v.begin(),v.end());
    print(v);
    //从大到小排序
    // sort(v.begin(),v.end(),[](int x,int y) ->bool {if(x>=y) return true;else return false;});
    sort(v.begin(), v.end(), greater_equal<int>());
    print(v);
    return 0;
}
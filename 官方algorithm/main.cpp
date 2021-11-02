#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <numeric>

using namespace std;

/*********************************************************************************************************
*                常用算法Algorithm
* 1.generate(v.begin(),v.end(),generator)  使用生成器初始化容器
* 2.for_each()                             遍历容器
* 3.transform()                            将容器的元素按照指定方法变换
* 4.find && find_if                        查找元素，返回元素位置迭代器
* 5.adjacent_ﬁnd()                         查找相邻重复元素,返回相邻元素的第一个位置的迭代器,没有则返回迭代器end()
* 6.count                                  统计元素出现次数
* 7.count_if                               按条件统计元素出现次数
* 8.binary_search                          查找指定的元素，查到 返回true 否则false,在无序序列中不可用
* 9.random_shuffle                         随即打乱顺序
* 10.sort                                  排序
* 11.merge                                 合并两个容器
* 12.reverse                               容器元素顺序反转，有序无序均可
* 13.copy                                  复制，目标容器必须指定大小
* 14.replace                               替换
* 15.replace_if                            条件替换
* 16.swap                                  交换两个容器元素，容器大小可不一样
* 17.accumalate                            累积求和 定义于头文件numeric
* 18.fill                                  填充
*
***********************************************************************************************************/
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

    //生成器初始化容器
    generate(v.begin(), v.end(), rand); 
    generate(v1.begin(), v1.end(), []() -> int
             {
                 static int x = 0;
                 return x++;
             });

    print(v);
    print(v1);
  

    //变换
    transform(v1.begin(), v1.end(), v.begin(), [](int &x) -> int
              { return x; });    //把容器元素复制到另一个容器
    transform(v1.begin(), v1.end(), v1.begin(), [](int &x) -> int
              { return x+1; });    //把容器元素+1
    print(v);
    print(v1);

    //查找
    auto it = find(v.begin(), v.end(), 5);
    cout << *it << endl;

    //条件查找
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

    //查找相邻的相同元素
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

    //二分查找，容器元素要有序排列
    if (binary_search(v1.begin(), v1.end(), 2))
        cout << "容器有元素2" << endl;

    //洗牌
    random_shuffle(v.begin(),v.end());
    print(v);

    //排序
    // sort(v.begin(),v.end(),[](int x,int y) ->bool {if(x>=y) return true;else return false;});
    sort(v.begin(), v.end(), less_equal<int>());
    print(v);
    
    //合并两个容器到新容器
    vector<int> *temp = new vector<int>(v1.size()+v.size());
    merge(v.begin(),v.end(),v1.begin(),v1.end(),temp->begin());
    
    //反转
    cout << "-----" << endl;
    reverse(temp->begin(),temp->end());
    print(*temp);
    
    //copy
    vector<int> v2(22);
    copy(temp->begin(),temp->end(),v2.begin());
    delete temp;
    print(v2);

    //replace
    cout << "v= ";print(v);
    replace(v.begin(),v.end(),2,0);
    cout << "v= ";print(v);

    //replace_if
    replace_if(v.begin(),v.end(),[](int &x) ->bool{if(x>0) return true;else return false;},1);
    cout << "v= ";print(v);
    
    //swap
    cout << "v= ";print(v);
    cout << "v1= ";print(v1);
    swap(v,v1);
    cout << "v= ";print(v);
    cout << "v1= ";print(v1);

    //accumalate
    int sum = accumulate(v.begin(),v.end(),0);
    cout << "sum(v) = " << sum << endl; 
    
    //fill
    fill(v1.begin(),v1.end(),0);
    print(v1);


    //交集 并集 差集
    vector<int> a1{1,2,3,4,5};
    vector<int> a2{4,5,6,7,8};
    vector<int> a3(10);

    // set_intersection(a1.begin(),a1.end(),a2.begin(),a2.end(),a3.begin());
    // set_union(a1.begin(),a1.end(),a2.begin(),a2.end(),a3.begin());
    set_difference(a2.begin(),a2.end(),a1.begin(),a1.end(),a3.begin());

    
    print(a3);




    return 0;
}
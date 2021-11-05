#include <iostream>
#include <tuple>
using namespace std;

/*
* pair 与 tuple
* pair 两个任意类型成员组成一个新的单元
* tuple又叫元组，它扩展了pair的概念，拥有任意数量的任意类型元素。
*/

auto print = [](const auto &p)
{ cout << "pair: {" << p.first << ", " << p.second << "}" << endl; };

//pair 作返回值
pair<int, int> getMultiNum()
{
    return make_pair(100,100);
}

int main()
{
    cout << "****************创建对组***************" << endl;
    pair<string, string> p{"name", "plainchan"};
    pair<string, int> p1;
    p1 = make_pair("age", 18);
    print(p);
    print(p1);

    cout << "****************返回对组***************" << endl;
    pair<int,int> num =getMultiNum();
    print(num);

    cout << "****************tie 解包********************" << endl;
    string name, name_val;
    tie(name, name_val) = p; //将组合数据解析为各个数据独立
    cout << name << " " << name_val << endl;

    cout << "******************创建tuple ***********************" << endl;
    tuple<string, string, int, float> t{"plain", "male", 24, 1.80};
    cout << get<0>(t) << endl;
    cout << get<1>(t) << endl;
    cout << get<2>(t) << endl;
    cout << get<3>(t) << endl; //获取元素

    return 0;
}
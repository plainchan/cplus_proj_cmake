#include <iostream>
#include <tuple>
using namespace std;

/*
* pair 与 tuple
*
*/

auto print = [](const auto &p)
{ cout << "pair: {" << p.first << ": " << p.second << "}" << endl; };
int main()
{
    cout << "****************创建对组***************" << endl;
    pair<string, string> p{"name", "plainchan"};
    pair<string, int> p1;
    p1 = make_pair("age",18);
    print(p);
    print(p1);


    cout << "****************tie 解包********************" << endl;
    string name,name_val;
    tie(name,name_val) = p;                        //将组合数据解析为各个数据独立
    cout << name <<" " << name_val <<endl;


    cout << "******************创建tuple ***********************"  << endl;
    tuple<string,string,int,float> t{"plain","male",24,1.80};
    cout << get<0>(t) << endl;
    cout << get<1>(t) << endl;
    cout << get<2>(t) << endl;
    cout << get<3>(t) << endl;         //获取元素

    return 0;
}
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
    tie(name,name_val) = p;
    cout << name <<" " << name_val <<endl;

    return 0;
}
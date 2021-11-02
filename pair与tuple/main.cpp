#include <iostream>

using namespace std;

/*
* pair 与 tuple
*
*/

auto print = [](const auto &p){};
int main()
{
    cout << "****************创建对组***************" << endl;
    pair<string,string> p{"name","plainchan"};

    // make_pair<string,string>("name","plainchan");
    
    return 0;
}
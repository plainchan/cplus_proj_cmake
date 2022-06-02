#include <iostream>
#include <map>
using namespace std;

void print(const map<string,int> &m)
{
    for(map<string,int>::const_iterator it = m.begin(); it != m.end(); it++)
    {
        // cout << (*it).first <<":" << (*it).second;
        cout << "\"" << it->first << "\"" <<":" << it->second << " ";
    }
    cout << endl;
}

void print(const multimap<string,int> &m)
{
    for(multimap<string,int>::const_iterator it = m.begin(); it != m.end(); it++)
    {
        // cout << (*it).first <<":" << (*it).second;
        cout << "\"" << it->first << "\"" <<":" << it->second << " ";
    }
    cout << endl;
}

int main()
{
    cout << "---------构造--------" << endl;
    map<string, int> m{{"a", 1}, {"b", 2},{"c", 3}};
    map<string, int> m1;
    m1["A"]=1;m1["B"]=2;m1["C"]=3;
    map<string, int> m2;
    m2.emplace(pair<string,int>("a",3));
    m2.emplace(pair<string,int>("b",2));
    m2.emplace(make_pair("c",1));
    m2.emplace(make_pair("d",0));
    map<string, int> m3(m2);
    multimap<string,int> mp{{"a", 1}, {"b", 2},{"c", 3},{"a", 1}, {"b", 2},{"c", 3}};
    cout << "m: " ;print(m);
    cout << "m1: " ;print(m1);
    cout << "m2: " ;print(m2);
    cout << "m3: " ;print(m3);
    cout << "ms: " ;print(mp);

    cout << "---------插入--大小--删除----" << endl;
    cout << "m: " ;print(m);
    m.emplace(pair<string,int>("d",4));
    m.emplace(make_pair("e",5));
    m.emplace(make_pair("e",6));
    m.emplace(map<string,int>::value_type("f",6));  //若键存在,则插入失败
    m["f"] = 7; //若键存在，会覆盖value
    cout << "m: " ;print(m);
    m.erase(m.begin());
    cout << "erase m: " ;print(m);
    m.clear();
    cout << "clear m: " ;print(m);

    cout << "---------查找--统计----" << endl;
    cout << "m1: " ;print(m1);
    cout << "mp: " ;print(mp);
    cout << "m1.find(\"A\")= " << m1.find("A")->second << endl;
    cout << "mp.count(\"a\")= " << mp.count("a") << endl;




    return 0;
}
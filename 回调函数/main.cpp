#include <iostream>
#include <vector>
using namespace std;
//登记回调函数
typedef void (*print)(const vector<int>&);


//回调函数
void printVector(const vector<int> &v)
{
    cout << "vector<int> [";
    for (vector<int>::const_iterator it = v.cbegin(); it != v.cend(); it++)
    {
        if (it != --v.cend())
            cout << *it << " ";
        else
            cout << *it;
    }
    cout <<"]"<<endl;
}

//
void showVector(const vector<int> &v,print p)
{
    p(v);
}

int main()
{
  vector<int> v{1,2,3,4,5};
  showVector(v,printVector);
  
  return 0;
}
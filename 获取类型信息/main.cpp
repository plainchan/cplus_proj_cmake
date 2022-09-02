#include <iostream>
#include <vector>
#include <typeinfo>
#include <cassert>

using namespace std;

void test_dataTypeName()
{
    cout << "typeid(int).name(): "<< typeid(int).name() << endl;
    cout << "typeid(float).name(): "<< typeid(float).name() << endl;
    cout << "(typeid(int) == typeid(float)): "<< (typeid(int) == typeid(float)) << endl;
}
template<class T>
void test_is_type_int()
{
    cout << is_same<int,T>::value << endl;
}


//随机生成大小为n的数组
template <typename T>
std::vector<T> geneVector(int n)
{
    assert(n > 0);
    srand(time(NULL));
    srand48(time(NULL));
    std::vector<T> arr(n);
 
    for (size_t i = 0; i < n; i++)
    {
        if(is_same<unsigned int,T>::value)
            arr[i] = rand();
        else if(is_same<double,T>::value || is_same<float,T>::value)
            arr[i] = drand48();
        else if(is_same<int,T>::value)
            arr[i] = mrand48();
        else
            arr[i] = rand();
  
    }
    return arr;
}
//打印数组
template <typename T>
void print(std::vector<T> &arr)
{
    int n = arr.size();
    std::cout << "[";
    for (size_t i = 0; i < n; i++)
    {
        if (i == n - 1)
            std::cout << arr[i] << "]"
                      << " size = " << n << std::endl;
        else
            std::cout << arr[i] << " ";
    }
}
int main()
{

    // {
    //     test_dataTypeName();
    // }
    // test_is_type_int<double>();
    auto v1 = geneVector<int>(6);
    print(v1);
    return 0;
}
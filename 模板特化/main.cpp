#include <iostream>
#include <vector>
#include <cassert>
#include <typeinfo>
#include <ctime>
using namespace std;


//随机生成大小为n的数组
template <typename T>
std::vector<T> geneVector(int n)
{
    assert(n > 0);
    srand(time(NULL));
    std::vector<T> arr(n);
    for (size_t i = 0; i < n; i++)
            arr[i] = rand();
    return arr;
}

template <>
std::vector<double> geneVector<double>(int n)
{
    assert(n > 0);
    srand48(time(NULL));
    std::vector<double> arr(n);
    for (size_t i = 0; i < n; i++)
            arr[i] = drand48();

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
    auto v1 = geneVector<double>(6);
    print(v1);
    // cout << "HelloWorld" << endl;
    return 0;
}
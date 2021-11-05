#include <iostream>
#include <tuple>
#include "example.hpp"
using namespace std;

int main()
{
    {
        cout << "全局函数作友元" << endl;
        Num num(1, 5);
        int m, n;
        tie<int, int>(m, n) = getNum(&num);
        cout << "m = " << m << endl;
        cout << "n = " << n << endl;
        
    }

    {
        cout << "成员函数作友元" << endl;
        Num num(1, 5);
        int m, n;
        tie<int, int>(m, n) = A::getNum(&num);
        cout << "m = " << m << endl;
        cout << "n = " << n << endl;

    }

    {
        cout << "类作友元" << endl;
        B b(100, 500);
        int m, n;
        tie<int, int>(m, n) = b.getNum();
        cout << "m = " << m << endl;
        cout << "n = " << n << endl;
    }

    return 0;
}
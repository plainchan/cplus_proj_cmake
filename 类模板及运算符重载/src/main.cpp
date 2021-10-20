#include "tarray.hpp"
#include <iostream>

using namespace std;
int main()
{
    Array<int> A(6, 3);
    Array<int> B(6, 3);
    Array<int> C(5, 3);
    Array<int> D(5, 0);
    Array<int> E(5, 0);

    // D = A - B - C;
    // cout << A - B - C << endl;

    cout << "A=" << A << endl;
    cout << "B=" << B << endl;
    cout << "A == B" ;
    if (A == B)
        cout << " true" << endl;
    else
        cout << " false" << endl;

    return 0;
}
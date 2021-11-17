#include <iostream>
#include <Eigen/Dense>

using namespace std;

int main()
{

    Eigen::Array<int,5,5> m(0);
    m(0,0) = 1;
    m(1,0) = 1;
    
    m(4,4) = 1;
    cout << m << endl;;
    cout << m.reverse() << endl;
    return 0;
}
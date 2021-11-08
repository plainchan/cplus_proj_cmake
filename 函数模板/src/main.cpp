#include "example.hpp"
#include <vector>
#include <deque>

using namespace std;


int main()
{
    deque<int> v{1,2,3,4,5};
    print<deque<int>>(v);
    return 0;
}
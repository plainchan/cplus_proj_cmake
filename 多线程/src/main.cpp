#include <iostream>
#include "simplecase.hpp"
#include <vector>
#include <chrono>
#include <ctime>
#include "unistd.h"
using namespace std;

int main()
{

    threadJoinOrDetach();
    threadFuncObj();
    while(1)
    {
        std::cout << "Hello World" << endl;
        sleep(1);
        
    }
    return 0;
}
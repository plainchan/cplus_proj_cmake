#include <iostream>
#include "utility.h"
using namespace std;



int main()
{

    char buff[1024];
    while(true)
    {
        fgets(buff,1024,stdin);
        cout << buff << endl;
    }
    return 0;
}
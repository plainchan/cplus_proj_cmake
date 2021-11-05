#include "example.hpp"
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{


  
  {
    class B
    {

    };
    Num *num;
    num->setNum(10);
    cout << num->getNum() << endl;
    cout << sizeof(B) << endl;
    return 0;
  }
}
#include "example.h"
#include <iostream>
using namespace std;

int NumPlus::num =0;
NumPlus::NumPlus()
{
  a = 0;
  num++;
}
void NumPlus::print()
{
  cout << "num==" << num << endl;
}
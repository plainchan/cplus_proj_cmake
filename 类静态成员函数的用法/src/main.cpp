#include "example.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
  Polygon::init();
  Polygon triangle(3);
  triangle.calcuSumAngle();

  cout << "180度 == " << triangle.rad(180.0) << endl;


  return 0;
}
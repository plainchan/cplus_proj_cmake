#include <iostream>
#include "example.h"
using namespace std;

float Polygon::pi =0;
Polygon::Polygon(int sides)
{
  this->sides = sides;
  this->degree = 0;
}
void Polygon::init()     //在类外定义时，前面不需要加static。
{
  pi = 3.1415926;
}

int Polygon::calcuSumAngle()
{ 
  int angle = (this->sides-2)*180;
  cout << this->sides << "边行內角和" << angle << endl;
  return angle;
}
float Polygon::rad(float degree)
{

  return degree*pi/180;
}
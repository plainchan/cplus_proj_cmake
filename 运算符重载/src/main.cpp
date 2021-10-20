// #include <iostream>
#include "example.h"
using namespace std;

int main()
{
  Array A(5, 1);
  Array B(5, 1);
  Array C(5, 1);
  Array D(5, 0);
  cout << A.p << endl;
  cout << B.p << endl;
  cout << C.p << endl;
  cout << D.p << endl;


  A = B =C =D;

  cout << A.p << endl;
  cout << B.p << endl;
  cout << C.p << endl;
  cout << D.p << endl;



  return 0;
}
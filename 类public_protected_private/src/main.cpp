#include <iostream>
#include "example.hpp"
using namespace std;

int main()
{
  Ring ring(500);
  cout << "ring price = " << ring.getPrice() <<endl;

  ring.setRingPrice(1000);
  cout << "ring price = " << ring.getPrice() <<endl;
  
  // ring.setPrice(1000);   //报错


  return 0;
}
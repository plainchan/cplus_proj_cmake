#ifndef __EXAMPLE_H__
#define __EXAMPLE_H__

#include <iostream>
using namespace std;

class Array
{
  friend ostream &operator<<(ostream &cout, Array &A);  //友元函数,当需要访问类私有函数时候
public:
  Array(int n);
  Array(int n, int val);
  ~Array();

  void print();

  Array(const Array &A);
  Array operator=(const Array &A);
  Array operator+(const int val);
  Array operator+(const Array &B);
  int& operator[](int index);

  int *p;
  int size;
  
};

// ostream &operator<<(ostream &cout, Array &A); //不需要访问类私有函数时候

#endif
#include "example.h"

using namespace std;
#include <iostream>



Array::Array(int n)
{
  p = new int[n];
  for (int i = 0; i < n; i++)
    p[i] = 0;
  size = n;
}
Array::Array(int n, int val)
{
  p = new int[n];
  for (int i = 0; i < n; i++)
    p[i] = val;
  size = n;
}

Array::~Array()
{
  delete[] p;
}

void Array::print()
{
  cout << "[";
  for (int i = 0; i < size - 1; i++)
    cout << p[i] << ",";
  cout << p[size - 1];
  cout << "]" << endl;
}

// 运算符重载
Array::Array(const Array &A)
{
  size = A.size;
  p = new int[A.size];
  for (int i = 0; i < A.size; i++)
    p[i] = A.p[i];
}
Array Array::operator=(const Array &A)
{
  if (this != &A)
  {
    this->size = A.size;
    for (int i = 0; i < A.size; i++)
      this->p[i] = A.p[i];
  }
  return *this;
}
Array Array::operator+(const int val)
{
  Array A(5, 0);
  for (int i = 0; i < size; i++)
  {
    A.p[i] = this->p[i] + val;
  }
  return A;
}
Array Array::operator+(const Array &B)
{
  Array C(size);
  for (int i = 0; i < size; i++)
  {
    C.p[i] = this->p[i] + B.p[i];
  }
  return C;
}


int& Array::operator[](int index)
{
  return p[index];
}
ostream &operator<<(ostream &cout, Array &A)
{
  cout << "[";
  for (int i = 0; i < A.size - 1; i++)
  {
    cout << A.p[i] << ",";
  }
  cout << A.p[A.size - 1] << "]";
  return cout;
}

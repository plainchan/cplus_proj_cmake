#ifndef EXAMPLE_HPP
#define EXAMPLE_HPP

#include <iostream>

template <typename T>
void print(T &t)
{
  std::cout << "[";
  for (auto it = t.cbegin(); it != t.cend(); it++)
  {
    if (it != --t.cend() )
      std::cout << *it << " ";
    else
      std::cout << *it;
  }
  std::cout << "]" << std::endl;
}

#endif
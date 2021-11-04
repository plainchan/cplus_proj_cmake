#ifndef EXAMPLE_HPP
#define EXAMPLE_HPP

#include <iostream>
class A
{
public:
    virtual void foo()
    {
        std::cout << "A::foo() is called" << std::endl;
    }
};

class B: public A
{
public:
    void foo()
    {
        std::cout << "B::foo() is called" << std::endl;
    }
};




#endif
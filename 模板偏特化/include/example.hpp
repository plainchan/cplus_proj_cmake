#ifndef EXAMPLE_HPP
#define EXAMPLE_HPP

#include <functional>

template<class T>
class Test;

template<class F,class ...Args>
class Test<F(Args...)>
{
public:
    Test()
    {
        // callback = std::bind(F,Args...);
    }

private:
 using return_type = typename std::result_of<F(Args...)>::type;
 std::function<return_type()> callback;

};



void test()
{
   Test<int(int)> t();
}
















#endif
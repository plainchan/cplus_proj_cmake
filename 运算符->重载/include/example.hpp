#ifndef EXAMPLE_HPP
#define EXAMPLE_HPP

#include <iostream>



class smartPoint
{
public:
    smartPoint()
    {
        ++count;
    }
    smartPoint(smartPoint&& s)
    {
        this->count=s.count;
    }

    smartPoint(smartPoint&s)
    {
        this->count=++s.count;
    }
    ~smartPoint()
    {
        --count;
    }
    int use_count()
    {
        return count;
    }



private:

    static int count;

};
int smartPoint::count=0;


void test()
{
    smartPoint s;
    std::cout << s.use_count() << std::endl;
}




















#endif
#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <iostream>

//单例模式
//懒汉模式
void test1()
{
    class Utility
    {

    public:
        void print(std::string &s)
        {
            std::cout << s << std::endl;
        }
        void print(std::string &&s)
        {
            std::cout << s << std::endl;
        }
        static Utility& instance()
        {
            //静态对象，只创建一次
            static Utility util;
            return util;
        }

    private:
        Utility(){print("constructor");};
        ~Utility(){print("deconstructor");};
        Utility(Utility &t)=delete;
        Utility(Utility &&t)=delete;
    };


    Utility::instance().print("hello world");
    Utility::instance().print("hello code");
    Utility::instance().print("hello job");

}







#endif
#ifndef EXAMPLE_HPP
#define EXAMOLE_HPP

#include <iostream>

/* 
* 在C++中 struct和class唯一的区别就在于 默认的访问权限不同
*    区别：
*    struct 默认权限为公共
*    class 默认权限为私有
*/

//struct 类
struct Person
{
    //默认为public
    Person(std::string name,int age)
    {
        this->name = name;
        this->age = age;
        salary = 10000;
    }
    ~Person(){}

    int getSalary()
    {
        return salary;
    }

    void setSalary(int val)
    {
        salary = val;
    }

    std::string name;
    int age;

private:
    int salary;


};







// 声明一个结构体
struct Vector3
{
    float x;
    float y;
    float z;
};

// 声明结构体并同时定义变量
struct Quaternion
{
    float x;
    float y;
    float z;
    float w;
} qtn1, qtn2;

// 声明结构体并同时定义变量和初始化
struct Pos
{
    float x;
    float y;
    float yaw;
} p1 = {0.0, 0.0, 1.57};

// 直接定义结构类型变量
struct
{
    std::string name;
    int age;

} person;

// 定义结构类型变量,并将这个变量定义成一种类型
// 这种方法好处是可以直接用变量名去定义变量
// 可以去参考typedef用法
// 不是给结构起别名，虽然看上去像
typedef struct
{
    Quaternion quaternion;
    Vector3 Vector;
    
}coordinate;



















#endif
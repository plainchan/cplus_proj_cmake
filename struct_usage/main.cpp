#include <iostream>
using namespace std;

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
    string name;
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

int main()
{
    
    return 0;
}
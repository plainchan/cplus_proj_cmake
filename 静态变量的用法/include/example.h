#ifndef __EXAMPLE_H__
#define __EXAMPLE_H__

#include <iostream>

//源文件(.cpp)定义全局变量
//头文件（.h)extern关键字声明 
//其他源文件需要用到，只需要包含该头文件即可
extern int number_global;
extern int x=100;

#endif
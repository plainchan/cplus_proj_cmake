using namespace std;
#include <iostream>

// 全局变量具有全局作用域。
// 全局变量只需在一个源文件中定义，就可以作用于所有的源文件。
// 当然，其他不包含全局变量定义的源文件需要用extern 关键字再次声明这个全局变量。
// 也可以在头文件（.h)extern关键字声明 
// 其他源文件需要用到，只需要包含该头文件即可
int number_global = 200;


#include <iostream>

using namespace std;

/* 
* 共用体，也叫联合体，在一个“联合”内可以定义多种不同的数据类型，
* 这些数据共享同一段内存，以达到节省空间的目的。
* union变量所占用的内存长度等于最长的成员的内存长度。
* 存储模式：
*  大端模式（Big_endian）：字数据的高字节存储在低地址中，而字数据的低字节则存放在高地址中。
*  小端模式（Little_endian）：字数据的高字节存储在高地址中，而字数据的低字节则存放在低地址中。
*/
union U_Demo
{
    char x;        // 1个字节
    short y;       // 2个字节
    int z;         // 4个字节
};                 //共享内存

int main()
{
    U_Demo u;
    
    cout << "u的size = " << sizeof(u) << endl;
    u.z = 0x41;                                 //65
    cout << "u.x = " << u.x << endl;
    cout << "u.y = " << u.y << endl;
    cout << "u.z = " << u.z << endl;
    return 0;
}
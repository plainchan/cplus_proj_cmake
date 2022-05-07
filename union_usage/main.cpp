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

/* 
*   共用体用途：将float数据拆分成4字节数据，将4字节数据转换成float
*/
union U_Demo1
{
    float  f_data;
    char   byte[4];
};   
union word
{
	short a;
	char b;
}c;
 
int checkCPU(void)
{
	c.a = 1;
	return (c.b == 1);
}
int main()
{
    {
        U_Demo u;
        
        cout << "u的size = " << sizeof(u) << endl;
        u.z = 0x41;                                 //65
        cout << "u.x = " << u.x << endl;
        cout << "u.y = " << u.y << endl;
        cout << "u.z = " << u.z << endl;
    }

    {
        //2.54   浮点数地址实际存放数据  0x40228f5c
        U_Demo1 u;
        u.byte[0]=0x5c;
        u.byte[1]=0x8f;
        u.byte[2]=0x22;
        u.byte[3]=0x40;
        
        cout << "浮点数" << u.f_data << endl;
    }
    {

        if ( checkCPU() )
            cout << "Little_endian" << endl;
        
        else
            cout << "Big_endian" << endl;
    }

    return 0;
}
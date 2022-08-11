#include <iostream>
#include <cstdlib>                             
using namespace std;

/**
 * void *malloc(size_t size)                    动态申请size个字节的内存空间
 * void *calloc(size_t nitems, size_t size)     用于向系统动态申请n个, 每个占size个字节的内存空间; 并把分配的内存全都初始化为零值。
 * void *realloc(void *ptr, size_t size)        将指针p所指向的已分配内存区的大小改为size 
 */

struct student
{
    int ID;
    string name;
};
 
int main()
{
    // {
    //     cout << "--------malloc不初始化分配的内存,calloc初始化已分配的内存为0--------" << endl;
    //     cout << "--------malloc分配的内存曾经被使用过,会遗留各种数据,没有被使用过,则为0--------" << endl;
    //     int *pnum1 = (int *)malloc(sizeof(int));
    //     int *pnum2 = (int *)calloc(1,sizeof(int));
    //     // int *p = pnum1;
    //     // for(int i=0;i<100;++i)
    //     // {
    //     //     cout <<  *p++ <<endl;
    //     // }
    //     cout << "num1 = " << *pnum1 << ", num2 = " << *pnum2 <<endl;

    //     free(pnum1);
    //     free(pnum2);
    // }

    // {
    //     student *pst1 = (student *)malloc(sizeof(student));
    //     student *pst2 = (student *)calloc(10,sizeof(student));
    //     free(pst1);
    //     free(pst2);
        
    // }

    {
        int *pnum1 = (int *)calloc(10,sizeof(int));
        pnum1[1]=100;
        pnum1 = (int *)realloc(pnum1,1);
        int *p = pnum1;
        
        for(int i=0;i<2;++i)
        {
            cout <<  *p++ <<endl;
        }

        cout <<  p[1] <<endl;   // p[1]无效
        free(pnum1);
    }
    return 0;
}                       


#include <iostream>
#include <vector>
#include <functional>
using namespace std;

typedef void (*Callback)(int,int);


void process_print(int a,int b)
{
    std::cout << "a = " << a << " " << "b = " <<  b <<std::endl;
}
void process_add(int a,int b)
{
    std::cout << "a + b = "<<" "<< a+b << std::endl;
}



// 1. std::function   类似C的函数指针
void processData_customized(int a,int b,std::function<void(int,int)> &processCallBack)
{
    processCallBack(a,b);
    cout << "type 1" << endl;
    cout <<  endl;
}

// 2. 重载，捕捉右值
// void processData_customized(int a,int b,std::function<void(int,int)> &&processCallBack)
// {
//     processCallBack(a,b);
//     cout << "type 2" << endl;
//     cout <<  endl;
// }

// // 3. 重载，c style, 等同于2,两者不可同时出现
// void processData_customized(int a,int b,Callback callback)
// {
//     callback(a,b);
//     cout << "type 3" << endl;
//     cout <<  endl;
// }

// 4. 重载，c style, 等同于2,两者不可同时出现
void processData_customized(int a,int b,Callback callback)
{
    callback(a,b);
    cout << "type 4" << endl;
    cout <<  endl;
}


int main()
{
    std::function<void(int,int)> f = process_print;
    processData_customized(1,2,f);  // type1

    processData_customized(1,2,process_add);  //type2 or type3 or type4
    processData_customized(1,2,[]
    (int x,int y)
    {
        cout << "a - b = " << x-y << endl;
    });                      //lamda  type2 or type3 or type4

    Callback callback = &process_print;
    processData_customized(1,2,callback);  //type2 or type3 or type4


    return 0;
}
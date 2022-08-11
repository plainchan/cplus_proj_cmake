#include <functional>
#include <iostream>
using namespace std;

/**
 * @brief  共享内存，将N bytes内存数据转换成特定数据
 * 
 * @tparam T  数据类型
 * @tparam N  数据类型大小
 */
template <typename T,std::size_t N>
union BytesConv
{
    uint8_t bytes[N];
    T       number;
};
/**
 * @brief  共享内存，将N bytes内存数据转换成特定数据
 * 
 * @tparam T 数据类型
 * @tparam N 数据类型大小
 * @param p  内存数据地址
 * @return T 返回内存数据转换的制定数据类型的值
 */
template <typename T,std::size_t N>
T Bytes2Num(const uint8_t* p)
{
    BytesConv<T,N> conv;
    for(int i=0;i<N;++i)
       conv.bytes[i]=p[i];
    return conv.number;
}


/**
 *  @brief brief description std::function 是通用多态函数包装器。 std::function 的实例能存储、复制及
 *  调用任何可复制构造的可调用目标——函数、 lambda 表达式、 bind 表达式或其他函数对象，还有指向成员函数指针和指向数据成员指针。
 *  存储的可调用对象被称为 std::function 的目标。若 std::function 不含目标，则称它为空。
 *  调用空 std::function 的目标导致抛出 std::bad_function_call 异常。
 *  std::function 满足可复制构造 (CopyConstructible) 和可复制赋值 (CopyAssignable) 。 
 *  @ref https://zh.cppreference.com/w/cpp/utility/functional/function
 */


std::function <float(const uint8_t*)> Byte2Float = Bytes2Num<float,4>;   
std::function <float(const uint8_t*)> Byte2INT16 = Bytes2Num<int16_t,2>;
std::function <float(const uint8_t*)> Byte2U16   = Bytes2Num<uint16_t,2>;




void process_print(int a,int b)
{
    std::cout << "a= " << a << " " << "b= " <<  b <<std::endl;
}
void process_add(int a,int b)
{
    std::cout << a <<" "<< b << std::endl;
}

//类似C的函数指针
void processData_customized(int a,int b,std::function<void(int,int)> &processCallBack)
{
    processCallBack(a,b);
}
//重载，捕捉右值
void processData_customized(int a,int b,std::function<void(int,int)> &&processCallBack)
{
    processCallBack(a,b);
}



int main(void)
{
    {
        cout << "-------------包装函数模板-----------" <<endl;
        uint8_t buff[4]={0x00,0x48,0xa4,0x44};   //1314.250
        std::cout << Byte2Float(buff) << std::endl;
    }

    {
        cout << "-------------类似C的函数指针-----------" <<endl;

        processData_customized(1,7,process_print);
        processData_customized(1,7,[]
        (int x,int y)
        {
            std::cout << "x+y= " << x+y << std::endl;
        });                                        //lamda

    }
    return 0;
}
#ifndef THREAD_FUTURE_HPP
#define THREAD_FUTURE_HPP


#include <future>
#include <mutex>
#include <condition_variable>

#include <queue>

#include <ctime>
#include <unistd.h>

#include <iostream>
#include <functional>

//std::async
long calcuSum(long n)
{
    long sum = 0;
    for(long i=0;i<n;++i)
        sum+=i;
    return sum;
}
void waitDataReady(unsigned int s=1)
{
    sleep(s);
}
void test_doAsyncWorkWhenWait()
{
    std::future<long> doSum = std::async(calcuSum,10);
    waitDataReady();
    std::cout<<"Sum is "<<doSum.get()<<std::endl;
}



// std::packaged_task
// std::packaged_task：  类模板，包装一个函数，该函数也可以绑定参数（非常类似std::function和std::bind），生成一个可调用对象(std::function)并保存
//                       生成新的std::packaged_task对象，该对象成员函数get_future返回一个future对象
//                       该对象重载了(),调用该函数对象，执行保存在内部的可调用对象，以原子方式存储返回的值，并将状态设置为 就绪
//                       
// 
// 用于用户传入一个自定义函数，该函数与future绑定执行异步任务

std::packaged_task<int()> task;
std::future<int> simplePackaged_task(std::function<int(int)> f,int args)
{
    task = std::packaged_task<int()>(std::bind(f,args));
    //task 会对象内部保存一个std::function<void()>可调用对象
    //重载操作符（），task()是一个函数对象，会在内部调用std::function<void()>可调用对象
    //同时在绑定时，已经把simplePackaged_task的参数绑定给可调用对象
    //simplePackaged_task的参数，就是内部调用函数的调用参数
    //这样操作的好处，是统一内部回调的格式(全部为void()),方便创建一个queue<std::function<void()>>的队列
    //具体如test_packaged_task()
    std::future<int> res = task.get_future();
    return res;
}

void test_Packaged_task_simplecase()
{
    auto res = simplePackaged_task([](int n)
    {
        int sum=0;
        for(int i=0;i<n;++i)
            sum+=i;
        return sum;
    },100); //返回一个future对象
 
    std::thread t([&]{
        task();              //执行这个函数对象
    });

    waitDataReady(1); //模拟主线程耗时操作，异步执行计算操作

    std::cout << res.get() << std::endl;

    t.join();
}




//数据准备需要时间长，在准备期间创建一个异步任务，这个任务由用户制定，返回值，参数为任意
//返回一个future绑定了用户自定义的函数的对象
//用户自定义的函数，该函数为任意参数，任意返回类型
template<class F,class... Args>
auto getPackageTask(F&&f,Args...args) ->std::future<typename std::result_of<F(Args...)>::type>
{
    using return_type = typename std::result_of<F(Args...)>::type;
    auto task = std::make_shared< std::packaged_task<return_type()> >(
            std::bind(std::forward<F>(f), std::forward<Args>(args)...)
        );

    //非常关键
    (*task)();  //执行函数，该函数执行结果可以同步给future


    std::future<return_type> res = task->get_future();
    return res;
}

void test_packaged_task()
{

    auto sum = getPackageTask([](int n){
        int sum =0;
        for(int i=0;i<n;++i)
            sum+=i;
        return sum;
    },100);
    sleep(1);
    // std::thread t(sum,1);
    waitDataReady();
    std::cout<<"Sum is "<<sum.get()<<std::endl;
    // t.join();
}






// std::promise 在一个线程t1中保存一个类型typename T的值，可供相绑定的std::future对象在另一线程t2中获取。
void threadPromise(std::promise<int> &p)
{
    
    std::this_thread::sleep_for(std::chrono::seconds(2));

    int value = 100;
    std::cout << "Setting P=" << value << std::endl;
    p.set_value(value);
    
}

void threadGetData(std::future<int> &f)
{
    auto value = f.get(); //阻塞

    std::cout << "getValue" << value << std::endl;
}
void test_promise()
{   
    std::promise<int>p;
    std::future<int> f = p.get_future();

    std::thread t1(threadPromise,std::ref(p));
    std::thread t2(threadGetData,std::ref(f));

    t1.join();
    t2.join();
}





//std::promise










#endif
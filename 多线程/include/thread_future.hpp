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
void mainThreadWork(unsigned int s=1)
{
    std::cout << "Main thread do work....." << std::endl;
    sleep(s);
    std::cout << "Main thread finish" << std::endl;
}
void test_doAsyncWorkWhenWait()
{
    std::future<long> doSum = std::async(calcuSum,10);
    mainThreadWork();
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
 
    std::thread t(std::move(task));   //使用std::move

    mainThreadWork(1); //模拟主线程耗时操作，异步执行计算操作

    std::cout << "async work result: " <<  res.get() << std::endl;

    t.join();
}




//数据准备需要时间长，在准备期间创建一个异步任务，这个任务由用户制定，返回值，参数为任意
//返回一个future绑定了用户自定义的函数的对象
//用户自定义的函数，该函数为任意参数，任意返回类型
std::queue< std::function<void()> > tasks;
std::thread threadPackagedTask;
template<class F,class... Args>
auto getPackageTask(F&&f,Args...args) ->std::future<typename std::result_of<F(Args...)>::type>
{
    using return_type = typename std::result_of<F(Args...)>::type;
    auto task = std::make_shared< std::packaged_task<return_type()> >(
            std::bind(std::forward<F>(f), std::forward<Args>(args)...)
        );

    std::future<return_type> res = task->get_future();

#if 0
    // std::thread t1(std::move(*task);
    // threadPackagedTask= std::move(t1);            //使用线程
#else
    tasks.emplace([task](){ (*task)(); });     //使用任务队列
#endif

    return res;
}

void test_packaged_task()
{

    auto sum = getPackageTask([](int n){
        std::cout<<"async work start... "<<std::endl;
        int sum =0;
        for(int i=0;i<n;++i)
            sum+=i;
        std::cout<<"async work finish "<<std::endl;
        return sum;
    },1000);
    // std::thread t(std::move(tasks.front()));
    mainThreadWork();
    std::cout<<"async work,Sum is: "<<sum.get()<<std::endl;
    // t.join();
    threadPackagedTask.join();
}





// std::promise 可提供线程之间的通信
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
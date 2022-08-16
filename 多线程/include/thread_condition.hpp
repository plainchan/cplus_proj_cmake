#ifndef THREAD_CONDITION_HPP
#define THREAD_CONDITION_HPP

#include <thread>
#include <mutex>
#include <condition_variable>

#include <queue>

#include <ctime>
#include <unistd.h>

#include <iostream>


std::mutex m;
std::queue<int> data;
std::condition_variable data_con;

void produce_data_thread()
{
    while(true)
    {
        std::lock_guard<std::mutex> lk(m);  //上锁
        srand(time(NULL));
        data.push(rand()%10);
        std::cout << data.size() << " " << std::endl;
        
        data_con.notify_all();  //唤醒等待线程
        sleep(1);
    }
}

void process_data_thread()
{
        
    while(true)
    {
        std::cout << "here" << std::endl;
        std::unique_lock<std::mutex> lk(m); //上锁
        data_con.wait(lk,[](){return data.size()>=10;});    
        
        std::cout << "data: ";
        while (!data.empty())
        {
            std::cout << data.front() << " " << std::endl;
            data.pop();
        }
        std::cout << std::endl;
        // lk.unlock();
        
    }
    
}
/**
 * @brief 生产函数每生产一个数据，通知处理函数
 *        处理函数检测生产的数据是否大于等于10个，true,则打印数据并清空，fasle,继续等待
 * 
 */
void test_condition()
{
    
    std::thread t1(produce_data_thread);
    std::thread t2(process_data_thread);
    

    t1.join();
    t2.join();
    
}


















#endif
/* Copyright (c) 2012 Jakob Progsch, Václav Zeman
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 *    1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 *
 *    2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 *
 *    3. This notice may not be removed or altered from any source
 *    distribution.
 */

#ifndef MYTHREADPOOL_HPP
#define MYTHREADPOOL_HPP

#include <thread>
#include <future>
#include <condition_variable>
#include <mutex>

#include <vector>
#include <queue>

#include <functional>
#include <memory>

#include <iostream>



/**
 * @brief 
 * @link https://github.com/progschj/ThreadPool
 * 
 */
class MyThreadPool
{
public:
    MyThreadPool(size_t n):stop_(false),count_(n)
    {
        // for循环注册线程
        // 注意while死循环是不会阻塞for循环的，因为那是属于注册线程的
        for(int i=0;i<n;++i)
            threadContainer_.emplace_back(
            [this]()
            {
                // 这个while死循环是非主线程里面的
                // for循环初始化是主线程的，所以while死循环不会影响主线程
                while(true)
                {
                    std::function<void()> task;

                    {
                        //所有新建的线程的程序执行到都会在这里阻塞休眠
                        std::unique_lock<std::mutex> lk(que_mutex_);
                        //唤醒时检查条件，条件为假时继续阻塞休眠，并释放锁
                        //必须要有stop_标识位，否则任务队列为空，唤醒线程准备退出时，无法退出
                        condition_.wait(lk,[this](){ return stop_ || !queTask_.empty();}); 
                        if(stop_ && queTask_.empty())
                            return;
                        task = std::move(queTask_.front());
                        queTask_.pop();
                    }

                    task();
                }
          
            }
        );

    }
    ~MyThreadPool()
    {
        {
            std::lock_guard<std::mutex> lk(que_mutex_);
            stop_ = true;
        }               //设置标识位
        condition_.notify_all();       //唤醒线程，退出标识位真，退出线程死循环

        for(auto &t:threadContainer_)
            if(t.joinable())
                t.join();
    }
    template<class F,class ...Args>
    decltype(auto) addTask(F&&f,Args&&...args)
    {
        using return_type =typename std::result_of<F(Args...)>::type;
        //1.为什么要用指针？
        //如果不用指针task是个局部变量，离开作用域会消亡
        //2.为什么用智能指针share_ptr,而不用普通指针
        // 指向局部变量的普通指针，会在局部变量消亡后变成野指针
        // 需要在堆区开辟内存，share_ptr会自动回收垃圾，也可以用new但是要自己管理内存
        auto task = std::make_shared< std::packaged_task<return_type()> >(
            std::bind(std::forward<F>(f),std::forward<Args>(args)...) 
        );  
        {
            std::lock_guard<std::mutex> lk(que_mutex_);
            queTask_.emplace([task]{(*task)();});      //捕获值，注意此时智能指针复制，指针引用数量加1,task消亡后，开辟的内存也不会被删除
        }
        condition_.notify_one();

        return task->get_future();
    
    }

    size_t getThreadCount()
    {
        return count_;
    }
    size_t getFreeThreadCount()
    {
        int free =0;

        return free;

    }
    size_t getTaskQueSize()
    {
        std::lock_guard<std::mutex> lk(que_mutex_);
        return queTask_.size();
    }

    void stop()
    {

        std::lock_guard<std::mutex> lk(que_mutex_);
        stop_ = true;
    
    }
private:

    std::vector<std::thread> threadContainer_;
    std::queue<std::function<void()>> queTask_;
    std::mutex que_mutex_;
    std::condition_variable condition_;
    bool stop_;
    size_t count_;

};






























#endif
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


class MyThreadPool
{
public:
    MyThreadPool(size_t n):stop_(false)
    {
        for(int i=0;i<n;++i)
            threadContainer_.emplace_back(
            [this]()
            {
                while(true)
                {

                }
            }
        );

    }
    ~MyThreadPool()
    {
        {
            std::lock_guard<std::mutex> lk(que_mutex_);
            stop_ = true;
        }

        for(auto &t:threadContainer_)
            if(t.joinable())
                t.join();
    }
    template<class F,class ...Args>
    decltype(auto) addTask(F&&f,Args&&...args)
    {
        using return_type =typename std::result_of<F(Args...)>::type;
        auto task = std::packaged_task<return_type()>(std::bind(std::forward<F>(f),std::forward<Args)(args...));

        {
            std::lock_guard<std::mutex> lk(que_mutex_);
            queTask_.emplace(task());
        }
        condition_.notify_one();
        auto res = task.get_future();

        return res;
    }

    size_t getThreadCount()
    {

    }
    size_t getFreeThreadCount()
    {

    }


private:

    std::vector<std::thread> threadContainer_;
    std::queue<void()> queTask_;
    std::mutex que_mutex_;
    std::condition_variable condition_;
    bool stop_;

};






























#endif
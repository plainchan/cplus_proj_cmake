#ifndef THREAD_ATOM_HPP
#define THREAD_ATOM_HPP

#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>

#include <vector>

#include <ctime>

#include <iostream>


// memory_order_relaxed,     无同步或顺序限制，只保证当前操作原子性
// memory_order_consume,     标记读操作，依赖于该值的读写不能重排到此操作前
// memory_order_acquire,     标记读操作，之后的读写不能重排到此操作前
// memory_order_release,     标记写操作，之前的读写不能重排到此操作后
// memory_order_acq_rel,     仅标记读改写操作，读操作相当于 acquire，写操作相当于 release
// memory_order_seq_cst      sequential consistency：顺序一致性，不允许重排，所有原子操作的默认选项



std::atomic_flag lock = ATOMIC_FLAG_INIT;
 

//原子操作实现自旋锁
void f(int n)
{
    for (int cnt = 0; cnt < 10; ++cnt) 
    {
        while (::lock.test_and_set(std::memory_order_acquire))  // 获得锁
             ; // 自旋
        std::cout << "Output from thread " << n << '\n';
        ::lock.clear(std::memory_order_release);               // 释放锁
    }
}
 
void test_spinlock_byAtomic_flag()
{
    std::vector<std::thread> v;
    for (int n = 0; n < 10; ++n) {
        v.emplace_back(f, n);
    }
    for (auto& t : v) {
        t.join();
    }
}
















#endif
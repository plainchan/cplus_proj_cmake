#ifndef INTERVAL_HPP
#define INTERVAL_HPP

#include <chrono>


class Interval
{
private:
    static std::chrono::high_resolution_clock::time_point start_;
    static std::chrono::high_resolution_clock::time_point stop_;
    static std::chrono::duration<double> time_span_;
public:
    static void start()
    {
        start_ = std::chrono::high_resolution_clock::now();
    }
    static void stop()
    {
        stop_ = std::chrono::high_resolution_clock::now();
    }   
    static double getInterval()
    {
        time_span_ = std::chrono::duration_cast<std::chrono::duration<double>>(stop_ - start_);
        return time_span_.count();
    }     
    Interval();
    ~Interval();
};
std::chrono::high_resolution_clock::time_point Interval::start_;
std::chrono::high_resolution_clock::time_point Interval::stop_;
std::chrono::duration<double> Interval::time_span_ = std::chrono::duration<double>::zero();


template<typename _Rep, typename _Period>
inline void delay(const std::chrono::duration<_Rep, _Period>& __rtime)
{
    if (__rtime <= __rtime.zero())
        return;
    auto __s = std::chrono::duration_cast<std::chrono::seconds>(__rtime);
    auto __ns = std::chrono::duration_cast<std::chrono::nanoseconds>(__rtime - __s);
    struct timespec __ts =
    {
        static_cast<std::time_t>(__s.count()),
        static_cast<long>(__ns.count())
    };
    while (::nanosleep(&__ts, &__ts) == -1 && errno == EINTR)
    { }
}


void test()
{
     using namespace std::chrono_literals;
    auto day = 24h;
    auto halfhour = 0.5h;
    std::cout << "one day is " << day.count() << " hours\n"
              << "half an hour is " << halfhour.count() << " hours\n";
}













#endif
#ifndef TIMER_USAGE_HPP
#define TIMER_USAGE_HPP

#include<iostream>
#include<asio.hpp>
#include<boost/bind/bind.hpp>



// 那么5秒后才会执行print，也就是说在执行io.run之前print是不会执行的。
// async_wait()
// 该函数调用并不会阻塞，会继续执行下面的代码，直到遇到run()为止。 一旦闹钟时间到，作为参数所提供的函数就会被相应调用。 


void test_timer_sync()
{
    asio::io_context io;
    asio::steady_timer t(io,asio::chrono::seconds(2));

    t.wait();

    io.run();
    std::cout << "Hello World" << std::endl;
}

void test_timer_async()
{
    asio::io_context io;
    asio::steady_timer t(io,asio::chrono::seconds(5));

    t.async_wait([](const asio::error_code&){
        std::cout << "Finished Hello" << std::endl;
    });

    //
    std::cout << "Async Hello 1" << std::endl;
    std::cout << "Async Hello 2" << std::endl;    
    std::cout << "Async Hello 3" << std::endl;
    //

    io.run();
    
}

 int test_deadline_timer() 
 { 
    asio::io_service io_service; 
    asio::deadline_timer timer(io_service, boost::posix_time::seconds(5)); 
    timer.async_wait([](const asio::error_code &ec){
        std::cout << "5 s." << std::endl; 
    }); 
   io_service.run(); 
 } 



//
void print(const asio::error_code&,asio::steady_timer* t,int *count)
{
  if (*count < 5)
  {
    std::cout << *count << std::endl;
    ++(*count);

    t->expires_at(t->expiry() + asio::chrono::seconds(1));
    t->async_wait(boost::bind(print,
          asio::placeholders::error, t, count));
  }
};
void test_completion_hander()
{
    int count = 0;
    asio::io_context io;
    asio::steady_timer t(io,asio::chrono::seconds(1));

    t.async_wait(boost::bind(print,
    asio::placeholders::error,&t,&count));
    
    io.run();
    std::cout << "Final count is " << count << std::endl;
}


//类封装
class Printer
{
public:
    Printer(asio::io_context &io):
    count_(0),
    timer_(io,asio::chrono::seconds(1))
    {
        timer_.async_wait(boost::bind(&Printer::print,this));
    }
    ~Printer()
    {

    }

    void print()
    {
        if (count_ < 5)
        {
        std::cout << count_ << std::endl;
        ++count_;

        timer_.expires_at(timer_.expiry() + asio::chrono::seconds(1));
        timer_.async_wait(boost::bind(&Printer::print,this));
        }
    }
private:
    asio::steady_timer timer_;
    int count_;
};

void test_member_function_async()
{

    asio::io_context io;
    Printer p(io);

    io.run();

    // asio::thread;
}












#endif
#ifndef PROCESS_USAGE_HPP
#define PROCESS_USAGE_HPP

#include <unistd.h>
#include <iostream>


//  每一次fork,当前的父进程或者父进程的子进程都要再创建一个新的子进程
void test_fork()
{
    int pid = fork();
    int pid1 = fork();
    

    std::cout << "Hello World" << std::endl;

}
void test_fork1()
{
    int pid = fork();

    
    while(1)
    {
        std::cout << "pid = " << pid << std::endl;
        sleep(1);
    }
}


// 在子进程中执行其他程序，即替换当前进程映像，
// 这就需要使用如下exec系列函数
// exec函数后面的程序将不再执行
void test_fork2()
{
    int pid = fork();
    
    if(pid ==0)
        if(execl("/home/pp/cplus_proj_cmake/linux_kernal_prog/build/child_exec",std::to_string(pid).c_str(),NULL,NULL)<0);
            std::cout << "error" << std::endl;
    while(1)
    {
        
        std::cout << "--------------------------------"<< std::endl;
        std::cout << "parent process,child pid = " << pid << std::endl;
        sleep(1);
    }
}


















#endif
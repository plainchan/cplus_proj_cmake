#ifndef UTILITY_H
#define UTILITY_H

#include <stdint.h>


// epoll事件有两种模型，边沿触发：edge-triggered (ET)， 水平触发：level-triggered (LT)

// 水平触发(level-triggered)

//     socket接收缓冲区不为空 有数据可读 读事件一直触发
//     socket发送缓冲区不满 可以继续写入数据 写事件一直触发

// 边沿触发(edge-triggered)

//     socket的接收缓冲区状态变化时触发读事件，即空的接收缓冲区刚接收到数据时触发读事件
//     socket的发送缓冲区状态变化时触发写事件，即满的缓冲区刚空出空间时触发读事件


// 事件宏
// EPOLLIN ： 表示对应的文件描述符可以读（包括对端SOCKET正常关闭）；
// EPOLLOUT： 表示对应的文件描述符可以写；
// EPOLLPRI： 表示对应的文件描述符有紧急的数据可读（这里应该表示有带外数据到来）；
// EPOLLERR： 表示对应的文件描述符发生错误；
// EPOLLHUP： 表示对应的文件描述符被挂断；
// EPOLLET： 将 EPOLL设为边缘触发(Edge Triggered)模式（默认为水平触发），这是相对于水平触发(Level Triggered)来说的。
// EPOLLONESHOT： 只监听一次事件，当监听完这次事件之后，如果还需要继续监听这个socket的话，需要再次把这个socket加入到EPOLL队列里


















uint16_t getEndian()
{
    typedef union endian
    {
        uint8_t byte;
        uint16_t num;
    }endian;
    endian e;
    e.num = 0x8000;
    return e.byte>0;
}























#endif
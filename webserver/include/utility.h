#ifndef UTILITY_H
#define UTILITY_H

#include <stdint.h>



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
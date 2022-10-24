#ifndef MEMORY_USAGE
#define MEMORY_USAGE

#include<unistd.h>
#include<cstdio>

// SYNOPSIS
//        int brk(void *addr);
//        void *sbrk(intptr_t increment);
// DESCRIPTION
//        brk()  and  sbrk()  change the location of the program break, which de‐
//        fines the end of the process's data segment (i.e., the program break is
//        the  first  location  after the end of the uninitialized data segment).
//        Increasing the program break has the effect of allocating memory to the
//        process; decreasing the break deallocates memory.
//        brk()  sets the end of the data segment to the value specified by addr,
//        when that value is reasonable, the system has enough  memory,  and  the
//        process does not exceed its maximum data size (see setrlimit(2)).
//        sbrk() increments the program's data space by increment bytes.  Calling
//        sbrk() with an increment of 0 can be used to find the current  location
//        of the program break.
// RETURN VALUE
//        On success, brk() returns zero.  On error, -1 is returned, and errno is
//        set to ENOMEM.

//        On success, sbrk() returns the previous program break.  (If  the  break
//        was  increased,  then this value is a pointer to the start of the newly
//        allocated memory).  On error, (void *) -1 is returned, and errno is set
//        to ENOMEM.
void test_brk_sbrk()
{


}



























#endif
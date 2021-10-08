#ifndef __EXAMPLE_H__
#define __EXAMPLE_H__

#include <iostream>

void keepLocalValueLive();
void LocalValueDestroye();

int number_global =200;
static int static_number_global =100;

#endif
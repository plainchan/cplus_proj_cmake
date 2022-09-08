#ifndef EXAMPLE_HPP
#define EXAMPLE_HPP

#include <cassert>
#include <chrono>
#include <vector>
#include "matplotlibcpp/matplotlibcpp.h"

namespace plt = matplotlibcpp;

template <typename T>
void quickSort(std::vector<T> &arr, int left, int right)
{
    // assert(left >= 0);
    // assert(right < int(arr.size()));
    if (left < right)
    {
        size_t pivot_pos = rand()%(right-left+1)+left;
        T pivot = arr[pivot_pos];
        std::swap(arr[pivot_pos],arr[right]);
        
        size_t i = left - 1;
        size_t temp = 0;

        // partition
        for (size_t j = left; j < right; j++)
        {
            if (arr[j] < pivot)
                std::swap(arr[j], arr[++i]);
        }
        std::swap(arr[right], arr[++i]);

        // recursion
        quickSort(arr, left, i - 1);
        quickSort(arr, i + 1, right);
    }
}

//随机生成大小为n的数组
std::vector<int> geneVector(int n)
{
    assert(n > 0);
    srand(time(NULL));
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++)
        arr[i] = rand();
    return arr;
}

void test()
{
    std::chrono::high_resolution_clock::time_point start, end;
    std::chrono::duration<double> time_span;

    std::vector<int>size={
    10,20,40,60,80,
    100,200,400,600,800,
    1000,2000,4000,6000,8000,
    10000,20000,40000,60000,80000,
    100000,200000,400000,600000,800000,
    1000000,2000000,4000000,6000000,8000000,
    10000000,20000000,40000000,60000000,80000000,
    100000000,200000000
    };
    std::vector<float>span;
    std::vector<float>logsize;
    for(auto &n:size)
    {
        auto arr = geneVector(n);
        logsize.emplace_back(log(n)/log(10));
        start = std::chrono::high_resolution_clock::now();
        quickSort(arr,0,n-1);
        end = std::chrono::high_resolution_clock::now();
        time_span = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
        span.emplace_back(time_span.count());
    }

    plt::plot(logsize,span);
    plt::show();
}







void test2()
{
    // Prepare data.
    int n = 5000;
    std::vector<double> x(n), y(n), z(n), w(n,2);
    for(int i=0; i<n; ++i) {
        x.at(i) = i*i;
        y.at(i) = sin(2*M_PI*i/360.0);
        z.at(i) = log(i);
    }
    
    // Set the size of output image = 1200x780 pixels
    plt::figure_size(1200, 780);

    // Plot line from given x and y data. Color is selected automatically.
    plt::plot(x, y);

    // Plot a red dashed line from given x and y data.
    plt::plot(x, w,"r--");

    // Plot a line whose name will show up as "log(x)" in the legend.
    plt::named_plot("log(x)", x, z);

    // Set x-axis to interval [0,1000000]
    plt::xlim(0, 1000*1000);

    // Add graph title
    plt::title("Sample figure");

    // Enable legend.
    plt::legend();

    plt::show();
}


#endif
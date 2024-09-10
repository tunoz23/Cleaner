#pragma once
#include <iostream>
#include <chrono>

struct Timer
{
    std::chrono::time_point<std::chrono::steady_clock> start, end;
    std::chrono::duration<double> duration;
    Timer()
        :duration(0)
    {
        start = std::chrono::high_resolution_clock::now();
    }
    ~Timer()
    {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        duration *= 1000.f;
        std::cout << "it took -> " << duration.count() << "ms\n";
    }
};
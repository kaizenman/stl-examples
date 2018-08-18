// std::clock
// returns the approximate processor time used by the process since the beginning
// of an implementation-defined era related to the program's execution.
// to convert result value to seconds divide it by CLOCKS_PER_SEC

// std::clock time may advance faster or slower than the wall clock,
//      depending on the execution resources given to the program by the OS
//      If the CPU is shared by other processes, std::clock time may advance slower than wall clock
//      If the current process is multithreaded and more than one execution core is available,
//      std:clock time may advance faster than wall clock


// Only the difference between two values returned by different calls to std::clock is meaningful

// On POSIX-compatible systems, clock_gettime with clock id CLOCK_PROCESS_CPUTIME_ID offers better resolution


#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <thread>

// the function f() does some time-consuming work
void f()
{
    volatile double d = 0;
    for(int n=0; n<100000; ++n)
        for(int m=0; m<10000; ++m)
            d+= d*n*m;
}

int main()
{
    std::clock_t c_start = std::clock();
    auto t_start = std::chrono::high_resolution_clock::now();

    std::thread t1(f);
    std::thread t2(f);
    t1.join();
    t2.join();
    std::clock_t c_end = std::clock();
    auto t_end = std::chrono::high_resolution_clock::now();

    std::cout << std::fixed << std::setprecision(2) << "CPU time used: "
              << 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC << " ms\n"
              << "Wall clock time passed: "
              << std::chrono::duration<double, std::milli>(t_end-t_start).count()
              << " ms\n";
}
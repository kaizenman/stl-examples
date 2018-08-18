// std::chrono::system_clock

// system-wide real time wall clock


// rep          - signed arithmetic type representing the number of ticks in the clock's duration
// period       - a std::ratio type representing the tick period of the clock, in seconds
// duration     - std::chrono::duration<rep, period>
// time_point   - std::chrono::time_point<std::chrono::system_clock>



// is_steady

// now
// to_time_t
// from_time_t

#include <chrono>

int main()
{
    CLOCK_REALTIME
    CLOCK_MONOTONIC

    clock_gettime()
}
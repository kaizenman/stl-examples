// chrono

// duration



// system_clock                     - wall clock time from the system-wide realtime clock
// steady_clock                     - monotonic clock that will never be adjusted
// high_resolution_clock            - the clock with the shortest tick period available
// time_point                       - a point in time
// treat_as_floating_point
// duration_values


// std::chrono::nanoseconds         - duration<at least 64 bits int, std::nano>
// std::chrono::microseconds        - duration<at least 55 bits int, std::micro>
// std::chrono::milliseconds        - duraction<at least 45 bits int, std::milli>
// std::chrono::seconds             - duration<at least 35 bits>
// std::chrono::minutes             - duration<at least 29 bits, std::ratio<60>>
// std::chrono::hours               - duration<at least 23 bits, std::ratio<3600>>

// C++20
// std::chrono::days                - duration<at least 25 bits, std::ratio<86400>>
// std::chrono::weeks               - duration<at least 22 bits, std::ratio<604800>>
// std::chrono::months              - duration<at least 20 bits, std::ratio<2629746>>
// std::chrono::years               - duration<at least 17 bits, std::ratio<31556962>>


// Literals
// _h
// _min
// _s
// _ms - milliseconds
// _us - microseconds
// _ns

#include <chrono>

// std::chrono::duration

// represents a time interval
// It consists of a count of ticks of type Rep and a tick period
//      tick period is a compile-time rational constant representing
//      the number of seconds from one tick to the next

// First template parameter - A duration representation can not be a duration
// Second template parameter of duration must be a std::ratio (fraction)
// Duration period must be positive

// The only data stored in a duration is a tick count of type Rep.
// If Rep is floating point, then the duration can represent fraction of ticks

#include <chrono>
#include <iostream>

constexpr auto year = 31556952ll; // seconds in average Gregorian year 

int main()
{
    using shakes = std::chrono::duration<int, std::ratio<1, 100000000>>;
    using jiffies = std::chrono::duration<int, std::centi>;
    using microfortnights = std::chrono::duration<float, std::ratio<14*24*60*60,  1000000>>;
    using nanocenturies = std::chrono::duration<float, std::ratio<100*year, 1000000000>>;

    std::chrono::seconds sec(1);
    std::cout << "1 second is:\n";

    std::cout << std::chrono::microseconds(sec).count() << " microseconds\n"
              << shakes(sec).count() << " shakes\n"
              << jiffies(sec).count() << " jiffies\n";

    // integer scale conversion with precision loss: requires a cast
    std::cout << std::chrono::duration_cast<std::chrono::minutes>(sec).count() << " minutes\n";

    // floating-point scale conversion: no cast
    std::cout << microfortnights(sec).count() << " microfortnights\n"
              << nanocenturies(sec).count() << " nanocenturies\n";



}
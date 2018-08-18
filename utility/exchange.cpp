// std::exchange

// this function can be used when implementing move assignment operators
// and move constructors

#include <utility>

struct S
{
    int* p;
    int n;

    S(S&& other)
        : p{std::exchange(other.p, nullptr)}
        , n{std::exchange(other.n, 0)}
    {}

    S& operator=(S&& other) {
        p = std::exchange(other.p, nullptr); // move p, while leaving nullptr in other.p
        n = std::exchange(other.n, 0);
        return *this;
    }

};
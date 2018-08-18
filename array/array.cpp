// std::array

// is a container that encapsulates fixed size arrays
// aggregate type with the same semantics as a struct holding a C-style array T[N] as its only non-static data member
// unlike C-style array, it doesn't decay to T* automatically
// As an aggregate type, it can be initialized with aggregate-initialization

// The default-constructed array is not empty

// The complexity of swapping is linear

// There is a special case for a zero-length array (N==0). In that case, array.begin() == array.end()
// which is some unique value. The effect of calling front() or back() on a zero-sized array is undefined

// An array can be used as a tuple of N elements of the same type

#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <array>

int main()
{
    std::array<int, 3> a1 { {1, 2, 3} }; // double-braces required in C++11 (not in C++14)
    std::array<int, 3> a2 = {1, 2, 3};   // never required after =
    std::array<std::string, 2> a3 = { std::string("a"), "b" };

    std::sort(a1.begin(), a1.end());
    std::reverse_copy(a2.begin(), a2.end(), std::ostream_iterator<int>(std::cout, " "));

    std::cout << '\n';

    for(const auto& s : a3)
        std::cout << s << ' ';
}
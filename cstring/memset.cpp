// std::memset 

// converts value ch to unsigned char and copies it into each of the first count characters of the object
// pointed to by dest.
// If the object is not trivially-copyable (e.g., scalar, array, or a C-compatible struct), the behavior is undefined
// If count is greater than the size of the object pointed to by dest, the behavior is undefined

// std::memset may be optimized away (under the as-if rules) if the object modified by this function is not accessed
// again for the rest of its lifetime. 
// For that reason, this function cannot be used to scrub memory (e.g. to fill an array that stored a password with zeroes).
// Solutions for that include C11 memset_s, FreeBSD explicit_bzero or Microsoft SecureZeroMemory

#include <iostream>
#include <cstring>

int main()
{
    int a[20];
    std::memset(a, 0, sizeof a);
    for (int ai : a) std::cout << ai;
}
// std::memmove

// Copies count characters from the object pointed to by src to the object pointed to by dest.
// Both objects are reinterpreted as arrays of unsigned char.

// Despite being specified "as if" a temporary buffer is used,
// actual implementation of this function do not incur the overhead of double copying or extra memory
// For small count, it may load up and write out registers;
// For larger blocks, a common approach (glibc and bsd libc) is to copy bytes forwards from
// the beginning of the buffer if the destination starts before the source, and backwards from the end otherwise,
// with a fall back to std::memcpy when there is no overlap at all

#include <iostream>
#include <cstring>

int main()
{
    char str[] = "1234567890";
    std::cout << str << '\n';
    std::memmove(str+4, str+3, 3); // copies from [4, 5, 6] to [5, 6, 7]
    std::cout << str << '\n';
}
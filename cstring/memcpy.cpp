// std::memcpy

// Copies count bytes from the object pointed to by src to the object pointed to by dest.
// Both objects are interpreted as arrays of unsigned char

// If the objects overlap, the behavior is undefined
// If either dest or src is a null pointer, the behavior is undefined, even if count is zero
// If the objects are not TriviallyCopyable, the behavior of memcpy is not specified and may be undefined

// std::memcpy is meant to be the fastest library routine for memory-to-memomry copy.
// It is usually more efficient than std::strcpy, which must scan the data it copies or std::memmove,
// which must take precautions to handle overlapping inputs

// Several C++ compilers transform suitable memory-copying loops to std::memcpy calls
// Where strict aliasing prohibits examining the same memory as values of two different types, std::memcpy may be used to convert the values


#include <iostream>
#include <cstdint>
#include <cstring>

int main()
{
    char source[] = "once upon a midnight dreary...", dest[4];
    std::memcpy(dest, source, sizeof dest);
    for (char c : dest)
        std::cout << c << '\n';

    double d = 0.1;
    std::int64_t n;
    std::memcpy(&n, &d, sizeof d);

    std::cout << std::hexfloat << d << " is " << std::hex << n << " as an std::int64_t\n";
}
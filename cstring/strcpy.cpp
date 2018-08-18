// std::strcpy

// Copies the character string pointed to by src, includeing the null terminator,
// to the character array whose first element is pointed to by dest

// The behavior is undefined if the dest array is not large enough.
// The behavior is undefined if the strings overlap

#include <iostream>
#include <cstring>
#include <memory>

int main()
{
    const char* src = "Take the test.";
    // src[0] = 'M' --- can't modify string literal

    auto dst = std::make_unique<char[]>(std::strlen(src)+1); // +1 for the null terminator
    std::strcpy(dst.get(), src);
    dst[0] = 'M';
    std::cout << src << '\n' << dst.get() << '\n';
}
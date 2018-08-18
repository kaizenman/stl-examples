// std::strcat

// Appends a copy of the character string pointed to by src to the end of the character string pointed to by dest.
// The character src[0] replaces the null terminator at the end of dest. The resulting byte string is null-terminated

// The behavior is undefined if the destination array is not large enough for the contents of both src and dest and the
// terminating null character
// The behavior is undefined if the strings overlap.

#include <cstring>
#include <cstdio>

int main()
{
    char str[50] = "Hello ";
    char str2[50] = "World!";
    std::strcat(str, str2);
    std::strcat(str, " Goodbye World!");
    std::puts(str);
}
// std::strncat

// Appends a byte string pointed to by src to a byte string pointed to by dest
// At most count characters are copied
// The resulting byte string is null-terminated
// The destination byte string must have enough space for the contents of both dest and src
//      plus the terminating null character, except that the size of src is limited to count


#include <cstring>
#include <cstdio>

int main()
{
    char str[50] = "Hello ";
    char str2[50] = "World!";
    std::strcat(str, str2);
    std::strncat(str, " Goodbye World!", 3);
    std::puts(str);
}
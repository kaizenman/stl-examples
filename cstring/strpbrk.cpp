// std::strpbrk

// scans the null-terminated byte string pointed to by dest for any character
// from the null-terminated byte string pointed to by breakset, and returns a pointer to that character

// The name stands for "string pointer break" because it returns a pointer to the first of the
// separator ("break") characters

#include <iostream>
#include <cstring>
#include <iomanip>

int main()
{
    const char* str = "hello world, friend of mine!";
    const char* sep = " ,!";

    unsigned int cnt = 0;
    do {
        str = std::strpbrk(str, sep);
        std::cout << std::quoted(str) << '\n';
        if (str) str += std::strspn(str, sep);
        ++cnt;

    } while(str && *str);

    std::cout << "There are " << cnt << " words\n";
}
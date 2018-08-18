// std::strncpy

// Copies at most count characters of the byte string pointed to by src (including the terminating null character) to
// character array pointed to by dest

// If count is reached before the entire string src was copied, the resulting character array is not null-terminated
// If, after copying the terminating null character from src, count is not reached, additional null characters are written
// to dest until the total of count characters have been written

// If the strings overlap, the behavior is undefined

#include <iostream>
#include <cstring>

int main()
{
    const char* src = "hi";
    char dest[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
    std::strncpy(dest, src, 5);

    std::cout << "The contents of dest are: ";
    for (char c : dest) {
        if(c) {
            std::cout << c << ' ';
        } else {
            std::cout << "\\0" << ' ';
        }
    }
    std::cout << '\n';
}
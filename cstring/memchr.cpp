// std::memchr

// Converts ch to unsigned char and locates the first occurence of that value in the initial count characters
// (each interpreted as unsigned char) of the object pointed to by ptr

// This function behaves as if it reads the characters sequenctially and stops as soon as matching character is found:
// if the array pointed to by ptr is smaller than count, but the match is found within the array, the behavior is well-defined (C++17)

#include <iostream>
#include <cstring>

int main()
{
    char arr[] = {'a', '\0', 'a', 'A', 'a', 'a', 'A', 'a'};
    char *pc = (char*) std::memchr(arr, 'A', sizeof arr);

    if (pc != NULL)
        std::cout << "search character found\n";
    else
        std::cout << "search character not found\n";
}
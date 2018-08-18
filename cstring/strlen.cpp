// std::strlen

// Returns the length of the given byte string, that is, the number of characters
// in a character array whose first element is pointed to by str up to and not including the first null character
// The behavior is undefined if there is no null character in the character array pointed to by str

#include <cstring>
#include <iostream>

int main()
{
    const char str[] = "how many characters does this string contain?";

    std::cout << "without null character: " << std::strlen(str) << '\n'
              << "with null character: " << sizeof str << '\n';
}
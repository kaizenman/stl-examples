// std::strstr

// Finds the first occurrence of the byte string target in the byte string pointed to by str
// The terminating null characters are not compared

#include <iostream>
#include <cstring>

int main()
{
    const char *str = "Try not. Do, or do not. There is no try.";
    const char *target = "not";
    const char *result = str;

    while ((result = std::strstr(result, target)) != NULL) {
        std::cout << "Found '" << target
                  << "' starting at '" << result << "'\n";
        ++result;
    }
}
// std::strchr

// Finds the first occurence of the chracter static_cast<char>(ch) in the byte string pointed to by str
// The terminating null character is considered to be a part of the string and can be found if searching for '\0'

// Return value
// Pointer to the found character in str, or a null pointer if no such character found

#include <iostream>
#include <cstring>

int main()
{
    const char * str = "try not. Do, or do not. There is no try.";
    const char target = 'T';
    const char * result = str;

    while((result = std::strchr(result, target)) != NULL) {
        std::cout << "Found '" << target << "' starting at '" << result << "'\n";
        ++result;
    }
}
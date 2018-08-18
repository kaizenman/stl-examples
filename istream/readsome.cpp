// std::basic_istream::readsome 

// Extracts up to count immediately available characters
// from the input stream.
// The extracted characters are stored into the character
// array pointed to by s

// The behavior of this function is highly implementation specific
// For example, when used with std::ifstream, some library
// implementations fill the underlying filebuf with data as soon
// as the file is opened (and readsome() on such implementations
// reads data, potentially, but not necessarily, the entire file),
// while other implementations only read from file when an actual
// input operation is requested (and readsome() issued after file
// opening never extracts any characters)
// Likewise, a call to std::cin.readsome() may return all pending
// unprocessed console input, or may always return zero and
// extract no characters


#include <iostream>
#include <sstream>

int main()
{
    char c[10] = {};
    std::istringstream input("This is sample text.");

    input.readsome(c, 5); // reads 'This ' and stores in c[0]..c[4]
    input.readsome(c, 9); // reads 'is sample' and stores in c[0]..c[8]
    std::cout << c;
}
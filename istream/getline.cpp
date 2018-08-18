// std::basic_istream::getline

// Extracts characters from stream until end of line or
// the specified delimiter delim.

// (1) basic_istream& getline( char_type* s, std::streamsize count)
// (2) basic_istream& getline( char_type* s, std::streamsize count,
//                         char_type delim); 


// The first version is equivalent to getline(s, count, widen('\n'))

// After constructing and checking the sentry object, extracts
// characters from *this and stores them in successive locations
// of the array whose first element is pointed to by s, until
// any of the following occurs
// - (#1) end of file condition occurs in the input sequence
//          setstate(eofbit) is executed
// - (#2) the next available character c is the delimiter
// - (#3) count-1 characters have been extracted
//          setstate(failbit) is executed  

// Because condition #2 is tested before condition #3,
// the input line that exactly fits the buffer does not trigger failbit

// Because the terminating character is counted as an extracted
// character, an empty input line does not trigger failbit






#include <iostream>
#include <sstream>
#include <vector>
#include <array>


int main()
{
    std::istringstream input("abc|def|gh");
    std::vector<std::array<char, 4>> v;

    // note: the following loop terminates 
    // when std::ios_base::operator bool() on the stream
    // returned from getline() returns false
    for (std::array<char, 4> a; input.getline(&a[0], 4, '|'); ) {
        v.push_back(a);
    }

    for (auto& a : v) {
        std::cout << &a[0] << '\n';
    }
}
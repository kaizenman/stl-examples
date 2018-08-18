// std::basic_istream::read

// Extracts characters from stream

// Characters are extracted and stored until any of the
// following condition occurs:
// - count characters were extracted and stored
// - end of file condition occurs on the input sequence
//          setstate(failbit|eofbit) is called.
//   The number of successfully extracted characters can
//   be queried using gcount()


// When using a non-converting locale (the default locale is 
// non-converting), the overrider of this function in
// std::basic_ifstream may be optimized for zero-copy bulk I/O
// (by means of overriding std::streambuf::xsgetn)

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdint>

int main()
{
    std::string bin = {'\x12', '\x12', '\x12', '\x12'};
    std::istringstream raw(bin);
    std::uint32_t n;
    if(raw.read(reinterpret_cast<char*>(&n), sizeof n))
        std::cout << std::hex << std::showbase << n << '\n';

    std::ofstream("test.txt", std::ios::binary) 
        << "abcd1\nabcd2\nabcd3";

    if (std::ifstream is{"test.txt", std::ios::binary | std::ios::ate}) {
        auto size = is.tellg();
        std::string str(size, '\0');
        is.seekg(0);
        if (is.read(&str[0], size))
            std::cout << str << '\n';
    }
}
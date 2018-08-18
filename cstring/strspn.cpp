// std::strspn

// Returns the length of the maximum initial segment (span) of the byte string pointed to by dest,
// that consists of only the caracters found in byte string pionted to by src

#include <cstring>
#include <string>
#include <iostream>

const char * low_alpha = "qertyuiopoadfghjklzxcvbnm";

int main()
{
    std::string s = "abcde312$#@";

    std::size_t spnsz = std::strspn(s.c_str(), low_alpha);
    std::cout << spnsz << '\n';
    std::cout << "After skipping initial lowercase letters from '" << s 
              << "'\nThe remainder is '" << s.substr(spnsz) << "'\n";
}       
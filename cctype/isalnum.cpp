// std::isalnum (OS-specific)

// checks if the given character is an alphanumeric character as classified by the current C locale
// In the default locale, the following characters are alphanumeric:
// - digits (0123456789)
// - uppercase leters (ABCDEFGHIJKLMNOPQRSTUVWXYZ)
// - lowercase letters (abcdefghijklmnopqrstuvwxyz)

// the behavior is undefined if the value of ch is not representable as unsigned char and is not equal to EOF

// Return value is int (non-zero value if the character is an alphanumeric character, 0 otherwise)


// To use function safely with plain char(or signed char), the argument should be first converted to unsigned char:
#include <cctype>

bool my_isalnum(char ch)
{
    return std::isalnum(static_cast<unsigned char>(ch));
}

// Should not be directly used with standard algorithms when the iterator's value type is char or signed char.
// Instead, convert the value to unsigned char first

#include <algorithm>
#include <string>

int count_alnums(const std::string& s)
{
    return std::count_if(s.begin(), s.end(),
                        // static_cast<int(*)(int)>(std::isalnum) --- wrong
                        // [](int c) { return std::isalnum(c); } --- wrong
                        // [](char c) { return std::isalnum(c); } --- wrong
                        [](unsigned char c) { return std::isalnum(c); });
}


#include <clocale>
#include <iostream>

int main()
{
    unsigned char c = '\xdf'; // German letter ß

    std::cout << "isalnum(\'\\xdf\', default C locale) returned " << std::boolalpha << (bool)std::isalnum(c) << '\n';

    if (std::setlocale(LC_ALL, "de_DE.iso88591"))
        std::cout << "isalnum(\'\\xdf\', ISO-8859-1 locale) returned " << std::boolalpha << (bool)std::isalnum(c) << '\n';
}
// std::strcoll

// Compares two null-terminated byte strings according to the current locale as
// defined by the LC_COLLATE category

// Return value is negative if lhs is less than rhs
//                 positive otherwise

// Collation order is the dictionary order: the position if the letter in the national alphabet (its equivalence class)
// has higher priority than its case or variant
// Within an equivalence class, lowercase characters collate before their uppercase equivalents and locale-specific order
// may apply to the characters with diacritics.
// In some locales, groups of characters compare as single collation units.
// For example, "ch" in Czech follows "h" and precedes "i", and "dzs" in Hungarian follows "dz" and precedes "g"

#include <iostream>
#include <cstring>
#include <clocale>

int main()
{
    std::setlocale(LC_COLLATE, "cs_DZ.iso88592");

    const char * s1 = "hrnec";
    const char * s2 = "chrt";

    std::cout << "In the Czech locale: ";
    if (std::strcoll(s1, s2) < 0)
        std::cout << s1 << " before " << s2 << '\n';
    else
        std::cout << s2 << " before " << s1 << '\n';

    std::cout << "in lexicographical comparison: ";
    if (std::strcmp(s1, s2) < 0)
        std::cout << s1 << " before " << s2 << '\n';
    else
        std::cout << s2 << " before " << s1 << '\n';
}
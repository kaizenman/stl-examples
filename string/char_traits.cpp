// std::char_traits

// Traits class template that abstracts basic character and string operations
// for a given character type.
// The defined operation set is such that generic algorithms almost always can be implemented
// in terms of it.
// It is thus possible to use such algorithms with almost any possible character of string type, just by
// supplying customized char_traits class

// user-defined traits may be used to provide case-insensitive comparison

#include <string>
#include <iostream>
#include <cctype>

struct ci_char_traits : public std::char_traits<char> {
    static char to_upper(char chc) { return std::toupper((unsigned char) ch); }
    static bool eq(char c1, char c2) { return to_upper(c1) == to_upper(c2); }
    static bool lt(char c1, char c2) { return to_upper(c1) < to_upper(c2); }
    static int compare(const char* s1, const char* s2, size_t n) {
        while(n-- != 0)
            if (to_upper(*s1) < to_upper(*s2)) return -1;
            if (to_upper(*s1) > to_upper(*s2)) return 1;
            ++s1; ++s2;
        return 0;
    }

    static const char* find(const char* s, int n, char a) {
        auto const ua(to_upper(a));
        while(n-- != 0)
        {
            if (to_upper(*s) == ua)
                return s;
            s++;
        }
        return nullptr;
    }
};

using ci_string = std::basic_string<char, ci_char_traits>;

std::ostream& operator<<(std::ostream& os, const ci_string& str) {
    return os.write(str.data(), str.size());
}

int main()
{
    ci_string s1 = "Hello";
    ci_string s2 = "heLLo";
    if (s1 == s2)
        std::cout << s1 << " and " << s2 << " are equal\n";
}
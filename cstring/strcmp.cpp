// std::strcmp

// compares two null-terminated byte strings lexicographically

// the behavior is undefined if lhs or rhs are not pointers to null-terminated strings

// Return value
// positive if lhs appears after rhs in lexicographical order
// negative if lhs apperse before rhs in lexicographical order
// zero if lhs and rhs compare equal

#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>

int main()
{
    std::vector<const char*> cats {"Heathcliff", "Snagglepuss", "Hobbes", "Garfield"};
    std::sort(cats.begin(), cats.end(), [](const char * strA, const char * strB) {
        return std::strcmp(strA, strB) < 0;
    });

    for (const char * cat : cats) {
        std::cout << cat << '\n';
    }
}
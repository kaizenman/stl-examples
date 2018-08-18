// std::memcmp

// Reinterprets the objects pointed to by lhs and rhs as arrays of unsigned char
// and compares the first count characters of these arrays. The comparison is done lexicographically

// The sign of the result is the sign of the difference between the values of the first pair of bytes
// (both interpreted as unsigned char) that differ in the objects being compared


// The function reads object representations, not the object values,
// and is typically only meaningful for trivially-copyable objects with no padding.
// For example, memcmp() between two objects of type std::string and std::vector will not
// compare their contents, and memcmp() between two objects of type struct {char c; int n;} will compare
// the padding bytes whose values may differ when the values of c and n are the same  

// Return value ----
// negative if the first differing byte in lhs is less than the corresponding byte in rhs
// 0 if all count bytes of lhs and rhs are equal
// positive value if the first differing byte in lhs is greater than the corresponding byte in rhs

#include <iostream>
#include <cstring>
#include <string>

void demo(const char* lhs, const char* rhs, std::size_t sz)
{
    std::cout << std::string(lhs, sz);
    int rc = std::memcmp(lhs, rhs, sz);
    if (rc == 0)
        std::cout << " compares equal to ";
    else if (rc < 0)
        std::cout << " precedes ";
    else if (rc > 0)
        std::cout << " follows ";
    std::cout << std::string(rhs, sz) << " in lexicographical order\n";
}

int main()
{
    char a1[] = {'a', 'b', 'c'};
    char a2[sizeof a1] = {'a', 'b', 'd'};

    demo(a1, a2, sizeof a1);
    demo(a2, a1, sizeof a1);
    demo(a1, a1, sizeof a1);
}
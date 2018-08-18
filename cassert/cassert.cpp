
// The definition of the macro assert depends on another macro, NDEBUG,
// which is not defined by the stl
// if NDEBUG is defined as a macro name at the point in the source code where
// <cassert> is included, then assert does nothing
// if NDEBUG is not defined, then assert checks if its argument (which must have scalar type)
// compares equal to zero. If it does, assert outputs implementation-specific diagnostic information
// on the standard error output and calls std::abort
// The diagnostic information is required to include the text of expression, as well as the values of
// the standard macros __FILE__, __LINE__, and the standard variable __func__


// Because assert is a function-like macro, commas anywhere in condition that are not protected by parentheses are
// interpreted as macro argument separators. Such commas are often found in template argument lists and list-initialization
//    assert(c == std::complex<double>{0, 0}); // error
//    assert((c == std::complex<double>{0, 0})); // OK

#include <cassert>

// uncomment to disable assert()
// #define NDEBUG

#include <iostream>

int main()
{
    assert(2+2==4);
    std::cout << "Execution continues past the first assert\n";
    assert(2+2==5);
    std::cout << "Execution continues past the second assert\n";
}
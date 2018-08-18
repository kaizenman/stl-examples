// <cstdarg> provides support for C-style variadic functions

// Types:
// va_list - is a complete object type suitable for holding the information needed by the macros va_start, va_copy,
//      va_arg, and va_end
// If a va_list instance is created, passed to another function, and used via va_arg in that function, then any
// subsequent use in the calling function should be preceded by a call to va_end
// It is legal to pass a pointer to a va_list object to another function and then use that object after the 
// function returns

// The va_start macro enables access to the variable arguments following the named argument parm_n.
// va_start should be invoked with an instance to a valid va_list objet ap before any calls to va_arg.
// If parm_n is declared with reference type or with a type not compatible with the type that results from default
// argument promotions, the behavior is undefined.

// va_start is required to support parm_n with overloaded operator&


// Macros:
// va_start
// va_arg
// va_copy
// va_end

#include <iostream>
#include <cstdarg>

int add_nums(int count, ...)
{
    int result = 0;
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; ++i) {
        result += va_arg(args, int);
    }
    va_end(args);
    return result;
}

int main()
{
    std::cout << add_nums(4, 25, 25, 50, 50) << '\n';
}
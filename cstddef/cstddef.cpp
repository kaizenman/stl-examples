
// size_t 
//          is a base unsigned integer type of C/C++ language
//          the type's size is chosen so that it can store the maximum size of
//          a theoretically possible array of any type
//          32 bit on 32bit system, 64-bit on 64bit system


//          for example (long long unsigned int or long unsigned int)

// ptrdiff_t
//          is a base signed integer type of C/C++ langauge
//          the type's size is chosen so that it can store the maximum size of
//          a theoretically possible array of any type
//          32 bit on 32bit system, 64-bit on 64bit system

//          for example (long long int or long int)

// ptrdiff_t is the type of the result of an expresison where one pointer is 
// subsctracted from the other (ptr1-ptr2)

// max_align_t

// is a trivial standard-layout type whose alignment requirements is at least as strict (as large)
// as that of every scalar type

// Pointers returned by allocation functions such as std::malloc are suitably aligned for any object
// which means they are aligned at least as strict as std::max_align_t

// is usually synonymous with the largest scalar type, which is long double on most platforms, and
// its alignment requirement is either 8 or 16

// alignof operator returns the alignment, in bytes, required for any instance of the type indicated by type-id,
// which is either complete type, an array type, or a reference type
// If the type is reference type, the operator returns the alignment of reference type
// If the type is array type, alignment requirement of the element type is returned

// nullptr_t

// is decltype(nullptr) - the type of the null pointer literal, nullptr. It is a distinct type that 
// is not itself a pointer type or a pointer to member type


// byte
//      (enum class byte : unsigned char {};)

// offsetof         - byte offset from the beginning of a standard-layout type to specified member
//      expands to an integral constant expression of type std::size_t, the value of which is the offset,
//      in bytes, from the beginning of an object of specified type to its specified member, including padding if any
//      If member is a static member or a member function, the behavior is undefined
//      The offset of the first member of a standard-layout type is always zero (empty-base optimization is mandatory)

// offsetof cannot be implemented in standard C++ and requires compiler support: GCC, LLVM
// offsetof throws no exceptions

#include <cstddef>
#include <iostream>

struct S {
    char c;
    double d;
};

void f(int * pi)
{
    std::cout << "Pointer to integer overload\n";
}

void f(std::nullptr_t nullp)
{
    std::cout << "null pointer overload\n";
}

int main()
{
    std::cout << "the first element is at offset " << offsetof(S,c) << '\n'
              << "the double is at offset " << offsetof(S, d) << '\n';  
    std::cout << alignof(std::max_align_t) << '\n';
    f(nullptr);
}
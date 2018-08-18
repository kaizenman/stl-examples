// std::allocator

// class template is default Allocator used by all stl containers if no user-specified
// allocator is provided

// All instances of the given allocator are interchangeable, compare equal
// and can deallocate memory allocated by any other instance of the same allocator type


// allocated
// deallocate



// std::allocator_traits
// provides the standardized way to access various properties of Allocators
// 

#include <memory>
#include <iostream>
#include <string>

int main()
{
    std::allocator<int> a1; // default allocator for ints

    int* a = a1.allocate(1); // space for one int
    a1.construct(a, 7);         // construct the int
    std::cout << a[0] << '\n';
    a1.deallocate(a, 1);        // deallocate space for one int

    // default allocator for strings
    std::allocator<std::string> a2;

    // same, but obtained by rebinding from the type of a12
    decltype(a1)::rebind<std::string>::other a2_1;

    std::allocator_traits<decltype(a1)>::rebind_alloc<std::string> a2_2;

    std::string* s = a2.allocate(2);  // space for 2 strings

    a2.construct(s, "foo");
    a2.construct(s + 1, "bar");

    std::cout << s[0] << ' ' << s[1] << '\n';

    a2.destroy(s);
    a2.destroy(s + 1);
    a2.deallocate(s, 2);`
}
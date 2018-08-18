// std::vector

// sequence container that encapsulates dynamic size arrays

// the elements are stored contiguosly (can be acessed not only through iterators,
// but also using offsets to regular pointers to elements).
// A pointer to an element of a vector may be passed to any function that expects a pointer to an element of an array

// Reallocations are usually constly operations in terms of performance
// The reserve() function can be used to eliminate reallocations if the number of elements is known beforehand

// Random access - constant complexity O(1)
// Insertion or removal of elements at the end - amortized constant O(1)
// Insertion or removal of elements - linear in the distance to the end of the vector O(n)

// A specialization of std::vector for the type bool is optimized for space efficiency

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v = {7, 5, 16, 8};

    v.push_back(25);
    v.push_back(13);

    for (int n : v) {
        std::cout << n << '\n';
    }

    // std::pmr::polymorphic_allocator CONT....
}
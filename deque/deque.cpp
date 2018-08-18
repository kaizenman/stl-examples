// std::deque

// double-ended queue) - indexed sequence container that allows fast insertion
//                       and deletetion at both its beginning and its end

// Opposed to std::vector, the elements of a deque are not stored contiguosly
// Typical implementations use a sequence of individually allocated fixed-size arrays
// with additional bookkeeping, which means indexed access to deque must perform the pointer dereferences,
// compared to vector's indexed access which performs only one

// The storage of a deque is automatically expanded and contracted as needed.
// Expansion of a deque is cheaper than the expansion of a std::vector, because it does not
// involve copying of the existing elements to a new memory location.
// On other hand, deques typically have large minimal memory cost;
// a deque holding just one element has to allocate its full internal array (8 times the object size of 64-bit libstdc++)
// 16 times the object size or 4096 bytes, whichever is larger, on 64-bit libc++)

// Random access - constant O(1)
// Insertion/removal at the end or beginning - constant O(1)
// Insertion/removal of elements - linear O(n) 


#include <iostream>
#include <deque>

int main()
{
    std::deque<int> d = {7, 5, 16, 9};

    d.push_front(13);
    d.push_back(25);

    for (int n : d) {
        std::cout << n << '\n';
    }
}
#include <algorithm>
#include <list>
#include <vector>
#include <iostream>
#include <numeric>
#include <random>
#include <functional>

// The wrapper more or less supports only one operation:
// an implicit type conversion back to the original type, yielding the original object

// The effect of std::reference_wrapper<> is to be able to use a reference as
// a "first class object," which you can copy and therefore pass by value to
// function templates. But you always finally need a conversion back to the
// underlying type

// Instances of std::reference_wrapper are objects (they can be copied or stored
// in containers) but they are implicitly convertible to T&, so that they
// can be used as arguments with the functions that take the underlying type by
// reference


int main()
{
    std::list<int> l(10);
    // fills the range with sequentially increasing values, starting with -4
    std::iota(l.begin(), l.end(), -4);
    std::vector<std::reference_wrapper<int>> v(l.begin(), l.end());

    // can't use shuffle on a list (requires random access), but can use it on a vector
    std::shuffle(v.begin(), v.end(), std::mt19937{std::random_device{}()});

    std::cout << "Contents of the list: ";
    for (int n : l) {
        std::cout << n << ' ';
    }

    std::cout << "\nContents of the list, as seed through a shuffled vector: ";
    for (int i : v) {
        std::cout << i << ' ';
    }

    std::cout << "\n\nDoubling the values in the initial list...\n\n";
    for (int& i  : l) {
        i *= 2;
    }

    std::cout << "Contents of the list, as seen through a shuffled vector: ";
    for (int i : v) {
        std::cout << i << ' ';
    }
}
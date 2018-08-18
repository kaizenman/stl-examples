// std::find_first_of

// Returns Iterator to the first element in the range[first, last) that is equal
// to an element from the range [s_first; s_last). If no such element is found, last is returned

#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v { 0, 2, 3, 25, 5};
    std::vector<int> t { 3, 19, 10, 2};

    auto result = std::find_first_of(v.begin(), v.end(), t.begin(), t.end());

    if (result == v.end()) {
        std::cout << "no elements of v were equal to 3, 19, 10 or 2\n";
    } else {
        std::cout << "found a match at " << std::distance(v.begin(), result) << '\n';
    }
}
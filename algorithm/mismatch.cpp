// std::mismatch

// returns the first mismatching pair of elements from two ranges


/*
template<class InputIt1, class InputIt2, class BinaryPredicate>
std::pair<InputIt1, InputIt2> mismatch(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p)
{
    while(first1 != last1 && p(*first1, *first2)) {
        ++first1, ++first2;
    }
    return std::make_pair(first1, first2);
}

*/


// the longest substring that is simultaneosly found at the very beginning of the give string
// and at the very end of it, in reverse order

#include <iostream>
#include <string>
#include <algorithm>

std::string mirror_ends(const std::string& in)
{
    return std::string(in.begin(), std::mismatch(in.begin(), in.end(), in.rbegin()).first);
}

int main()
{
    std::cout << mirror_ends("abXYZba") << '\n'
              << mirror_ends("abca") << '\n'
              << mirror_ends("aba") << '\n';
}
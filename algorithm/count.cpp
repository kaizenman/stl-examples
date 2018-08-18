// std::count

// For the number of elements in the range[first, last) without any additional criteria,
// use std::distance


/*
template<class InputIt, class UnaryPredicate>
typename iterator_traits<InputIt>::difference_type count(InputIt first, Input last, UnaryPredicate p)
{
    typename iterator_traits<InputIt>::difference_type ret = 0;
    for (; first != last; ++first) {
        if(p(*first)) {
            ret++;
        }
    }
    return ret;
}
*/


#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v { 1, 2, 3, 4, 4, 3, 7, 8, 9, 10 };

    // determine how many integers in a std::vector match a target value

    int target1 = 3;
    int target2 = 5;

    int num_items1 = std::count(v.begin(), v.end(), target1);
    int num_items2 = std::count(v.begin(), v.end(), target2);

    std::cout << "number: " << target1 << " count: " << num_items1 << '\n';
    std::cout << "number: " << target2 << " count: " << num_items2 << '\n';

    int num_item3 = std::count_if(v.begin(), v.end(), [](int i) { return i % 3 == 0; });
    std::cout << "number divisible by three: " << num_items3 << '\n';
}


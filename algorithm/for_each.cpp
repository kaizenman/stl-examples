// std::for_each

// Unlike the rest of the algorithms, for_each is not allowed to make copies of the elements
// in the sequence even if the are trivially copyable

/*
template<class InputIt, class UnaryFunction>
UnaryFunction for_each(Input first, Input last, UnaryFunction f)
{
    for(; first != last; ++first) {
        f(*first);
    }
    return f;
}
*/


// To compute the sum, it is recommended to use the dedicated algorithm std::accumulate

#include <vector>
#include <algorithm>
#include <iostream>

struct Sum
{
    Sum() : sum{0} {}
    void operator()(int n) { sum += n; }
    int sum;
};

int main()
{
    std::vector<int> nums {3, 4, 2, 8, 16, 267};

    auto print = [](const int& n) { std::cout << " " << n; };

    std::cout << "before:";
    std::for_each(nums.begin(), nums.end(), print);
    std::cout << '\n';


    std::for_each(nums.begin(), nums.end(), [](int &n) { n++; });

    Sum s = std::for_each(nums.begin(), nums.end(), Sum());

    std::cout << "after: ";
    std::for_each(nums.begin(), nums.end(), print);
    std::cout << '\n';
    std::cout << "sum: " << s.sum << '\n';
}
// std::move_if_noexcept

// move_if_noexcept 
// obtains rvalue reference if move constructor does not throw exceptions or if there is no copy constructor
// obtains lvalue reference otherwise

// std::vector::resize uses std::move_if_noexcept
// If an exception occurs during this operation
// std::vector::resize undoes everything it did to this point


// Return std::move(x) or x, depending on exception guarantees

#include <iostream>
#include <utility>

struct Bad
{
    Bad() {}
    Bad(Bad&&) // may throw
    {
        std:: cout << "Throwing move constructor called\n";
    }
    Bad(const Bad&) // may throw
    {
        std::cout << "Throwing copy constructor called\n";
    }
};

struct Good
{
    Good() {}
    Good(Good&&) noexcept // will not throw
    {
        std::cout << "Non-throwing move constructor called\n";
    }
    Good(const Good&) noexcept // will not throw
    {
        std::cout << "Non-throwing copy constructor called\n";
    }
};

int main()
{
    Good g;
    Bad b;
    Good g2 = std::move_if_noexcept(g);
    Bad b2 = std::move_if_noexcept(b);
}
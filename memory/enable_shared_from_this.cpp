#include <memory>
#include <iostream>

// std::enable_from_this

// enable_shared_from_this provides the safe alternative to an expression like
// std::shared_ptr<T>(this), which is likely to result in this being destructed more than once
// by multiple owners that are unaware of each other

// Publicly inheriting from std::enable_shared_from_this<T> provides the type T
// with a member function shared_from_this. 


struct Good : std::enable_shared_from_this<Good>
{
    std::shared_ptr<Good> getptr() {
        return shared_from_this();
    }
};

struct Bad
{
    std::shared_ptr<Bad> getptr() {
        return std::shared_ptr<Bad>(this);
    }
    ~Bad() { std::cout << "Bad::~Bad() called\n"; }
};

int main()
{
    // Good: the two shared_ptr's share the same object
    std::shared_ptr<Good> gp1 = std::make_shared<Good>();
    std::shared_ptr<Good> gp2 = gp1->getptr();
    std::cout << "gp2.use_count() = " << gp2.use_count() << '\n';

    // Bad: shared_from_this is called without having std::shared_ptr owning the caller
    try {
        Good not_so_good;
        std::shared_ptr<Good> gp1 = not_so_good.getptr();
    } catch(std::bad_weak_ptr& e) {
        // undefined behavior (until C++17) and std::bad_weak_ptr thrown (since C++17)
        std::cout << e.what() << '\n';
    }

    // Bad, each shared_ptr thinks it's the only owner of the object
    std::shared_ptr<Bad> bp1 = std::make_shared<Bad>();
    std::shared_ptr<Bad> bp2 = bp1->getptr();
    std::cout << "bp2.use_count() = " << bp2.use_count() << '\n';
    // double-delete of Bad
}
#include <iostream>
#include <type_traits>
#include <functional>

struct MyBind {
    typedef int result_type;
    int operator()(int a, int b) const { return a + b; }
};

namespace std {
    template<>
    struct is_bind_expression<MyBind> : public true_type {};
}

int f(int n1, int n2)
{
    return n1+n2;
}

int main()
{
    auto b = std::bind(f, MyBind(), 2);
    std::cout << "Adding 2 to the sum of 10 and 11 gives " << b(10, 11) << '\n';   
}
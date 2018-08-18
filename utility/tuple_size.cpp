#include <iostream>
#include <utility>
#include <tuple>

template<typename T>
void test(T t)
{
    int a[std::tuple_size<T>::value];
    std::cout << std::tuple_size<T>::value << '\n';
}

int main()
{
    test(std::make_tuple(1, 2, 3.14));
    test(std::make_pair(1, 3.14));
}
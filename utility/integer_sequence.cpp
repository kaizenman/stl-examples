#include <tuple>
#include <iostream>
#include <array>
#include <utility>

// convert array into a tuple
template<typename Array, std::size_t... I>
auto a2t_impl(const Array& a, std::index_sequence<I...>)
{
    return std::make_tuple(a[I]...);    
}

template<typename T, std::size_t N, typename Indices = std::make_index_sequence<N>>
auto a2t(const std::array<T, N>& a)
{
    return a2t_impl(a, Indices{});
}


template<typename Ch, typename Tr, typename Tuple, std::size_t... Is>
void print_tuple_impl(std::basic_ostream<Ch,Tr>& os,
                      const Tuple& t,
                      std::index_sequence<Is...>)
{
    ((os << (Is == 0  ? "" : ", ") << std::get<Is>(t)), ...);
}

template<typename Ch, typename Tr, typename... Args>
auto& operator<<(std::basic_ostream<Ch, Tr>& os,
                 const std::tuple<Args...>& t)
{
    os << "(";
    print_tuple_impl(os, t, std::index_sequence_for<Args...>{});
    return os << ")";
}


int main()
{
    std::array<int, 4> array = {1, 2, 3, 4};

    auto tuple = a2t(array);
    static_assert(std::is_same<decltype(tuple), std::tuple<int, int, int, int>>::value, "");

    std::cout << tuple << '\n';
}
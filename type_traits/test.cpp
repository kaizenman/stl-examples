
#include <type_traits>
#include <iostream>
#include <array>
#include <typeinfo>



template<typename T>
struct Rank : public std::integral_constant<size_t, 0>
{

};

template<typename T>
struct Rank<T[]> : public std::integral_constant<size_t, Rank<T>::value + 1>
{

};

template<typename T, size_t N>
struct Rank<T[N]> : public std::integral_constant<size_t, Rank<T>::value + 1>
{

};

template<typename T>
constexpr size_t Rank_v = Rank<T>::value;




template<typename T, unsigned N = 0>
struct Extent : public std::integral_constant<size_t, 0>
{
};

// partial specializations

template<typename T>
struct Extent<T[], 0> : public std::integral_constant<size_t, 0>
{

};


template<typename T, size_t N>
struct Extent<T[N], 0> : public std::integral_constant<size_t, N>
{
    
};

// 
template<typename T, unsigned N>
struct Extent<T[], N> : public std::integral_constant<size_t, N-1>::value
{
};

template<typename T, size_t N1, unsigned N2>
struct Extent<T[N1], N2> : public std::integral_constant<size_t, Extent<T, N2-1>::value>
{
};

template<typename T, unsigned N = 0>
constexpr size_t Extent_v = Extent<T, N>::value;


int main()
{
    int arr[] = {1, 2, 3, 4};

    int twoArr[2][5] = {
        {5, 2, 1, 3, 6}, {3, 6, 2, 1, 4}
    }; 

    static_assert(Rank_v<decltype(arr)> == 1, "Wrong result");
    static_assert(Extent_v<decltype(arr)> == 4, "Wrong result");
    static_assert(Extent_v<decltype(twoArr)> == 2, "Wrong result");
    static_assert(Extent_v<decltype(twoArr), 1> == 5, "Wrong result");

}
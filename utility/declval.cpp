// std::declval

// sometimes we don't have the objects available
// that we need to pass to an expression to evaluate it in decltype
// we might even not be able to create those object at all

// decltype(f(11)) - what type will I get when I call f with 11?
//                   what we actually mean is
//                   what type will I get when I call f with some int

#include <utility>


// sum_t is the type I get when I add some T to some U

template<typename T, typename U>
using sum_t = decltype(std::declval<T>() + std::declval<U>());

template<typename C>
decltype(std::declval<const C>().begin()) second(const C& c)
{
    
}
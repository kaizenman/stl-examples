// std::as_const

// alternatives:
//  use const_cast<const T&>(object)
//  or const_cast<std::add_const<decltype(object)>::type&>(object)

// 1. Forms lvalue reference to const type of t
// 2. const rvalue reference overload is deleted to disallow rvalue arguments



#include <string>
#include <cassert>
#include <utility>
#include <type_traits>

int main()
{
    std::string mutableString = "hello world";
    const std::string& constView = std::as_const(mutableString);


    assert(&constView == &mutableString);
    assert(&std::as_const(mutableString) == &mutableString);

    using WhatTypeIsIt = std::remove_reference_t<decltype(std::as_const(mutableString))>;

    static_assert(std::is_same<std::remove_const_t<WhatTypeIsIt>, std::string>::value,
        "should be some kind of string");
    static_assert(!std::is_same<WhatTypeIsIt, std::string>::value,
        "shouldn't be a mutable string");
}
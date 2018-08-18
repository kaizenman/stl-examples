#include <iostream>
#include <iomanip>
#include <functional>
#include <string>
#include <unordered_set>


// The actual hash functions are implementation-dependent and are not
// required to fulfill any other quality criteria except
// 1. operator() const accepts a single parameter of type Key
// 2. operator() const returns a value of size_t that represents the hash value
//    of the parameter
// 3. operator() const does not throw exceptions when called
// 4. operator() const For two parameters k1 and k2 that equal,
//      std::hash<Key>()(k1) == std::hash<Key>()(k2)
// 5. operator() const for two different parameters k1 and k2 that are
//      not equal, the probability that
//      std::hash<Key>()(k1) == std::hash<Key>()(k2) should be very small
//      approaching 1.0/std::numeric_limits<size_t>::max()

// Hash functions are only required to produce the same result for the same input
// within a single execution of a program;
// this allows salted hashes that prevent collision DoS attacks

// There is no specialization for C strings
// std::hash<const char*> produces a hash of the value of the pointer
//  (the memory address)
//  it does not examine the contents of any character array


// Each standard library header that declares the template std::hash provides
// enabled specializations of std::hash for std::nullptr_t and all cv-unqualified
// arithmetic types, all enumeration types, and all pointer types
// All member functions of all standard library specializations of this template
// are noexcept except for the member functions of std::hash<std::optional>,
// std::hash<std::variant> and std::hash<std::unique_ptr>

struct S {
    std::string first_name;
    std::string last_name;
};

bool operator==(const S& lhs, const S& rhs) {
    return lhs.first_name == rhs.first_name && lhs.last_name == rhs.last_name;
}

struct MyHash
{
    std::size_t operator()(S const& s) const noexcept
    {
        std::size_t h1 = std::hash<std::string>{}(s.first_name);
        std::size_t h2 = std::hash<std::string>{}(s.last_name);
        return h1 ^ (h2 << 1); // or use boost::hash_combine
    }
};

namespace std
{
    template<> struct hash<S>
    {
        typedef S argument_type;
        typedef std::size_t result_type;
        result_type operator()(argument_type const& s) const noexcept
        {
            result_type const h1 (std::hash<std::string>{}(s.first_name));
            result_type const h2 (std::hash<std::string>{}(s.last_name));
            return h1 ^ (h2 << 1);
        }
    };
}

int main()
{
    std::string str = "Meet the new boss...";
    std::size_t str_hash = std::hash<std::string>{}(str);
    std::cout << "hash(" << std::quoted(str) << ") = " << str_hash << '\n';

    S obj = { "Hubert", "Farnsworth"};
    // using the standalone function object
    std::cout << "hash(" << std::quoted(obj.first_name) << ','
              << std::quoted(obj.last_name) << ") ="
              << MyHash{}(obj) << " (using MyHash)\n or "
              << std::hash<S>{}(obj) << " (using injected std::hash<S> specialization\n";

    std::unordered_set<S> names = {obj, {"Bender", "Rodriguez"}, {"Leela", "turanga"}};

    std::hash<std::nullptr_t>

    for(auto& s: names)
        std::cout << std::quoted(s.first_name) << ' ' << std::quoted(s.last_name) << '\n';
}
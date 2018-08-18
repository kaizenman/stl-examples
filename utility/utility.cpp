
// swap                         - swaps the values of two objects
// exchange                     - replaces the value of obj with new_value and returns the old value of obj
// forward                      - forwards a function argument 
//                                Forwarding references preserve the value category (lvalue or rvalue) of a function argument
//                                  template<class T>
//                                  int f(T&& x) -> x is a forwarding reference
//                                  auto&& vec = foo(); // foo() may be lvalue or rvalue, vec is a forwarding reference


// move                         - obtains an rvalue reference. Exactly equivalent to a static_cast to an rvalue reference type/
// move_if_noexcept             - obtains an rvalue reference if the move constructor does not throw
// as_const                     - obtains a reference to const to its argument
// declval                      - obtains a reference to its argument for use in unevaluated context
// make_pair                    - creates a pair object of type, defined by the argument types

// to_chars ........
// from_chars .......


// Classes

// pair                         - struct template that provides a way to store two
//                                  heterogeneous objects as a single unit.
//                                  A pair is a specific case of a std::tuple with two elems
// integer_sequence             - represetnt a compile-time sequence of integers
//                                  when used as an argument to a function template, the parameter
//                                  pack Ints can be deduced and used in pack expansion
//                                  std::index_sequence is defined for the common case where T is std::size_t


// chars_format (C++17)


// Helpers
// piecewise_construct_t        - is an empty struct tag type used to disambiguate between different functions that take
//                                 two tuple arguments
// piecewise_construct
// in_place
// in_place_type
// in_place_index
// in_place_type_t
// in_place_index_t


// tuple
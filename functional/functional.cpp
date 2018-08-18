
// constants:

// _1, _2, _3, _4, ...


// classes:

// function                 - wraps callable object of any type with specified function call signature
// mem_fn                   - creates a function object out of a pointer to a member
// bad_function_call        - the exception thrown when invoking an empty std::function
// is_bind_expression       - if T is the type produced by ca call to std::bind, this template 
//                            is derived from std::true_type, for any other type, this template is 
//                            derived from std::false_type
// is_placeholder           - if T is the type of a standard placeholder (_1, _2, _3, ...), then this
//                            template is derived from 
//                            std::integral_constant<int, 1>, std::integral_constant<int, 2>
//                            std::integral_constant<int, 3>, ... 
// reference_wrapper        - class template that wraps a reference in a copyable, assignable object
//                            mechanism to store references inside standard containers (like std::vector)
//                            which cannot normally hold references  


// Hashing

// hash                     - hash function object

// Functions

// bind                     - binds one or more arguments to a function object
// ref                      - creates a std::reference_wrapper with a type deduced from its argument
// cref                     - creates a std::reference_wrapper with a type deduced from its argument
// invoke                   - invokes any callable object with given arguments


// Function Objects

// plus
// minus
// multiplies
// divides
// modulus
// negate


// Comparasions (operator())

// equal_to
// not_equal_to
// greater
// less
// greater_equal
// less_equal


// Logical operations

// logical_and
// logical_or
// logical_not


// Bitwise operators

// bit_and
// bit_or
// bit_xor
// bit_not


// Negators

// not_fn


// Searchers

// default_searcher                 
// boyer_moore_searcher
// boyer_moore_horspool_searcher



// Deprecated in C++11 and removed in C++17

// unary_function
// binary_function
// binder1st
// binder2nd
// bind1st
// bind2nd
// pointer_to_unary_function
// pointer_to_binary_functoin
// ptr_fun
// mem_fun_t
// mem_fun1_t
// const_mem_funt
// const_mem_fun1_t
// mem_fun
// mem_fun_ref_t
// mem_fun1_ref_t
// const_mem_fun_ref_t
// const_mem_fun1_ref_t
// mem_fun_ref


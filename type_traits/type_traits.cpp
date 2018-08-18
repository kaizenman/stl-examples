
// Helper classes

// integral_constant                        wraps a static constant of speciffied type. It is the base class for C++ type traits
// bool_constant                            helper alias template where T is bool 
// true_type                                std::integral_constant<bool, true>
// false_type                               std::integral_constant<bool, false>


// Primary type categories

// is_void                                  checks whether T is a void type.
// is_null_pointer                          checks if a type is std::nullptr_t
// is_integral                              checks if a type is integral_type
// is_floating_point                        checks if a type is floating-point type
// is_array                                 checks if a type is an array type
// is_enum                                  checks if a type is an enumeration type
// is_union                                 checks if a type is an union type
// is_class                                 checks if a type is a non-union class type
// is_function                              checks if a type is a function type
// is_pointer                               checks if a type is a pointer type
// is_lvalue_reference                      checks if a type is lvalue reference
// is_rvalue_reference                      checks if a type is rvalue reference
// is_member_object_pointer                 checks if a type is a pointer to a non-static member object
// is_member_function_pointer               checks if a type is a pointer to a non-static member function

// Composite type categories (Any type is either fundamental or compond)

// is_fundamental                           checks if a type is fundamental type (arithmetic type, void, or nullptr_t)
// is_arithmetic                            checks if a type is arithmetic type (integral type or a floating-point type)
// is_scalar                                checks if a type is scalar type (arithmetic, pointer, pointer to member, enum, or nullptr_t)
// is_object                                checks if a type is object type (any type other than function, refernce, or void)
// is_compound                              checks if a type is compound type (array, function, object pointer, function pointer, member
//                                              function ponter, reference, class, union, or enumeration, including cv variants)
// is_reference                             checks if a type is either lvalue reference or rvalue reference
// is_member_pointer                        checks if a type is a pointer to a non-static member function or object


// Type properties

// is_const                                 checks if a type is const-qualified
// is_volatile                              checks if a type is volatile-qualified
// is_trivial                               checks if a type is trivial (scalar type, a trivially copyable class with a trivial default constructor, 
//                                              or array of such type/class )
// is_trivially_copyable                    checks if a type is trivially copyable (copy, move ctor, copy assignment, move assignment operator is trivial or deleted)
//                                              at least one copy ctor, move ctor,  copy assignemtn operator, or move assignment operator is
//                                              non-deleted
//                                              trivial non-deleted destructor
// is_standard_layout                       checks if a type is standard-layout type (scalar type, standard-layout class, or an array of such type)
// is_pod                                   checks if a type is plain-old data (POD) type
// is_literal_type                          checks if a type is literal type
// has_unique_object representations        checks if every bit in the type's object representation contributes to its values
// is_empty                                 checks if a type is class (but not union) type and has no data
// is_polymorphic                           checks if a type is polymorphic class type
// is_abstract                              checks if a type is abstract class type
// is_final                                 checks if a type is a final class type
// is_aggregate                             checks if a type is an aggregate type
// is_signed                                checks if a type is signed arithmetic type
// is_unsigned                              checks if a type is unsigned arithmetic type


// Supported operations

// is_constructible
// is_trivially_constructible               // checks if a type has a constructor for specific arguments
// is_nothrow_constructible

// is_default_constructible
// is_trivially_default_constructible       // checks if a type has a default constructor
// is_nothrow_default_constructible

// is_copy_constructible
// is_trivially_copy_constructible          // checks if a type has a copy constructor
// is_nothrow_copy_constructible

// is_move_constructible
// is_trivially_move_constructible          // checks if a type can be constructed from an rvalue reference
// is_nothrow_move_constructible

// is_assignable
// is_trivially_assignable                  // checks if a type has a assignemnt operator for a specific argument
// is_nothrow_assignable                    

// is_copy_assignable
// is_trivially_copy_assignable             // checks if a type has a copy assignment operator
// is_nothrow_copy_assignable

// is_move_assignable
// is_trivially_move_assignable             // checks if a type has a move assignment operator
// is_nothrow_move_assignable

// is_destructible
// is_trivially_destructible                // checks if a type has a non-deleted destructor
// is_nothrow_destructible

// has_virtual_destructor                   // checks if a type has a virtual destructor

// is_swappable_with
// is_swappable                             // checks if objects of a type can be swapped with objects of same or different type
// is_nothrow_swappable_with
// is_nothrow_swappable



// Property queries

// alignemnt_of                             obtains the type's alignment requirements
// rank                                     obtains the number of dimensions of an array type
// extent                                   obtains the size of an array type along a specified dimension


// Type relationships

// is_same                                  checks if two types are the same
// is_base_of                               checks if a type is derived from the other type
// is_convertible                           checks if a type can be converted to the other type
// is_nothrow_convertible                   
// is_invocable                             checks if a type can be invoked (as if by std::invoke) with the given argument types
// is_invocable_r
// is_nothrow_invocable
// is_nothrow_invocable_r


// Const-volatily specifers

// remove_cv
// remove_const
// remove_volatile
// add_cv
// add_const
// add_volatile


// References

// remove_reference
// add_lvalue_reference
// add_rvalue_reference


// Pointers

// remove_pointer
// add_pointer


// Sign modifiers

// make_signed
// make_unsigned


// Arrays

// remove_extent
// remove_all_extents


// Miscellaneous transformations

// aligned_storage                          defines the type suitable for use as uninitialized storage for types of given size
// aligned_union                            defines the type suitable for use as uninitialized storage for all given types
// decay                                    applies type tranformations as when passing a function argument by value
// remove_cvref             
// enable_if                                hides a function oberload or template specialization based on compile-time boolean
// conditional                              chooses one type or another based on compile-time boolean
// common_type                              determines the common type of a group of types
// underlying_type                          obtains the underlying integer type for a given enumeration type
// result_of_invoke_result                  deduces the result type of invoking a callable object with a set of arguments
// void_t                                   void variadic alias template


// Operations on traits

// condjuction                              variadic logical AND metafunction
// disjunction                              variadic logical OR metafunction
// negation                                 lotgical NOT metafunction


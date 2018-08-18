// std::basic_string () ------ CONT.----->>

// stores and manipulates sequences of char-like object, which are non-array objects of trivial standard-layout type
// The class is dependent neither on the character type nor on the nature of operations on that type
// The definitions of the operations are supplied via the Traits template parameter
// Traits::char_type and CarT must name the same type; otherwise the behavior is undefined

// The elements of a basic_string are stored contiguosly, that is, for a basic_string s,
// &*(s.begin() + n) == &*s.begin() + n for any n in [0, s.size()), 
// or, equivalently, a pointer to s[0] can be passed to functions that expect a pointer to the first element of a CharT[] array

// Member functions -------------
// operator=
// assign
// get_allocator

// Element access ---------------
// at
// operator[]
// front
// back
// data
// c_str
// operator basic_string_view

// Iterators --------------------
// begin, cbegin, end, cend, rbegin, crbegin, rend, crend

// Capacity ---------------------
// empty
// size
// length
// max_size
// reserve
// capacity
// shrink_to_fit

// Operations --------------------
// clear
// insert
// erase
// push_back
// pop_back
// append
// operator+=
// compare
// replace
// substr
// copy
// resize
// swap

// Search -------------------------
// find
// rfind
// find_first_of
// find_first_not_of
// find_last_of
// find_last_not_of


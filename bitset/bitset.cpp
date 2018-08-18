
// std::bitset


// reference            - proxy class representing a reference to a bit

// operator==
// operator!=


// [] unlike test(), does not throw exceptions: the behavior is undefined if pos is out of bounds
// bool operator[]       - accesses the bit at position pos.
//                           returns the value of the bit
// constexpr bool operator[]
// reference operator[]  - returns an object of type std::bitset::reference that allows modification
//                         of the value


// test             - retruns the value of the bit at the position pos
//                    unlike operator[], performs a bounds check and throws std::out_of_range
//                    if pos does not correspond to a valid position in the bitset                        

// all              - checks if all bits are set to true
// any              - checks if any bits are set to true
// none             - checks if none of the bits are set to true
// count            - returns the number of bits set to true
// size             - returns the size number of bits that the bitset can hold
// operator&=
// operator|=
// operator^=
// operator~
// operator<<=
// operator>>=
// operator>>
// set
// reset
// flip
// to_string
// to_ulong
// to_ullong
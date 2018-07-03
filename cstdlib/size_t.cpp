#include <cstdlib>

// std::size_t is the unsigned integer type of the result of the sizeof operator
// as well as the sizeof... operator and the alignof operator

// std::size_t can store the maximum size of a theoretically possible object of any type
// (including array)

// A type whose size cannot be represented by std::size_t is ill-formed
// On many platforms (an exception is systems with segmented addressing) std::size_t 
// can safely store the value of any non-member pointer, in which case it is synonymous with
// std::uintptr_t

// std::size_t is commonly used for array indexing and loop counting.
// Programs that use other typese, such as unsigned int, for array indexing may fail on,
// e.g. 64 bit-systems when the index exceeds UINT_MAX or if it relies on 32-bit modular arithmetic

// When indexing C++ containers, such as std::string, std::vector, etc, the appropriate type is
// the member typedef size_type provided by such containers. It is usually defined as a synonym
// for std::size_t

//#include <cstdlib>
//#include <cstdio>
//#include <cstring>
//#include <ctime>
//#include <cwchar>
#include <cstddef>
#include <iostream>

int main()
{
	const std::size_t N = 10;
	int * a = new int[N];

	for(std::size_t n = 0; n < N; ++n)
		a[n] = n;
	for(std::size_t n = N; n-- > 0; )
		std::cout << a[n] << " ";

	delete[] a;
}
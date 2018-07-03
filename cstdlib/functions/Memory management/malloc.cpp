// std::malloc

// Allocaates size bytes of uninitialized storage
// If allocation succeeds, returns a pointer to the lowest (first) byte
// in the allocated memory block that is suitably aligned for any scalar type
// If size is zero, the behavior is implementation defined (null pointer may be returned),
// or on some non-null pointer may be returned that may not be used to access storage,
// but has to be passed to std::free

// Following functions are required to be thread_safe:
// - library versions of operator new and operator delete
// - user replacement versions of global operator new and operator delete
// - std::calloc, std::malloc, std::realloc, std::aligned_alloc (C++17)

// This function does not call constructors or initialize memory in any way.

#include <iostream>
#include <cstdlib>
#include <string>

int main()
{
	// allocates enough for an array of 4 strings
	if (auto p = (std::string*)std::malloc(4 * sizeof(std::string)))
	{
		int i = 0;
		try 
		{
			for (; i != 4; ++i) // populate the array
				new(p + i) std::string(5, 'a' + i);

			for (int j = 0; j  != 4; ++j) // print it back out
				std::cout << "p[" << j << "] == " << p[j] << '\n';
		}
		catch(...) {}

		for(; i != 0; --i) // clean up
			p[i - 1].~basic_string();

		std::free(p);
	}
}
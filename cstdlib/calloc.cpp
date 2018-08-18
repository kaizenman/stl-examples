// std::calloc

// Allocates memory for an array of num objects of size size and initializes  it
// to all bits zero

// If allocation succeeds, returns a pointer to the lowest (first) byte in the allocated
// memory block that is suitably aligned for any object type.

// If size is zero, the behavior is implementation defined (null pointer may be returned),
// or some non-null pointer may be returned taht may not be used to access storage)

// Due to the alignement requirements, the number of allocated bytes is not necessarily equal
// to num*size.
// Initialization to all bits zero does not guarantee that a floating-point or a pointer
// would be initialized to 0.0 and the null

// On failure returns a null pointer

#include <iostream>
#include <cstdlib>

int main()
{
	int* p1 = (int*)std::calloc(4, sizeof(int));	// allocate and zero out an array of 4 int
	int* p2 = (int*)std::calloc(1, sizeof(int[4])); // same
	int* p3 = (int*)std::calloc(4, sizeof *p3);     // same

	if(p2)
		for (int n = 0; n < 4; ++n)
			std::cout << "p2[" << n << "] == " << p2[n] << '\n';

	std::free(p1);
	std::free(p2);
	std::free(p3);
}
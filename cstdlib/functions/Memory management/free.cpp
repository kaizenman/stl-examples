// std::free

// Deallocates the space previously allocated by 
// std::malloc, std::calloc, std::aligned_alloc or std::realloc

// If ptr is a null pointer, the function does nothing
// The behavior is undefined if the vaue of ptr does not equal a value returned earlier
// by malloc, calloc, alligned_alloc or realloc

// The behavior is undefined if the memory are referred to by ptr has already been deallocated,
// that is std::free or std::realloc has already been called with ptr as the argument and
// no calls to std::malloc, std::calloc, std::aligned_alloc or std::realloc resulted
// in a pointer equal to ptr afterwards

// The behavior is undefined if after std::free returns, and access is made through the
// pointer ptr

// The function accepts (and does nothing with) the null pointer to reduce the amount
// of special-casing. Whether allocation succeds or not, the pointer returned by an
// allocation function can be passed to std::free

#include <cstdlib>

int main()
{
	int* p1 = (int*)std::malloc(10*sizeof *p1);
	std::free(p1);

	int* p2 = (int*)std::calloc(10, sizeof *p2);
	int* p3 = (int*)std::realloc(p2, 1000*sizeof *p3);
	if(p3)
		std::free(p3);
	else
		std::free(p2);
}
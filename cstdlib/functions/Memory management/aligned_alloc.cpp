// std::aligned_alloc

// Allocate size bytes of uninitialized storage whose alignment is specified by alognment. 
// The size parameter must be an integral multipe of aligment

// Passing a size which is not an integral multiple of alignment or an alignment
// which is not valid or not supported by the implementation causes the function
// to fail and return a null pointer

// Regular std::malloc aligns memory suitable for any object type (which, in practice,
// means that it is aligned to alignof(std::max_align_t)). This function is useful
// for over-aligned allocations, such as to SSE, cache line, or VM page boundary

#include <cstdio>
#include <cstdlib>

int main()
{
	int * p1 = static_cast<int*>(std::malloc(10*sizeof *p1));
	std::printf("default-aligned address:     %p\n", static_cast<void*>(p1));
	std::free(p1);

	int * p2 = static_cast<int*>(_aligned_malloc(1024, 1024));
	std::printf("1024-byte aligned address:   %p\n", static_cast<void*>(p2));
	std::free(p2);
}
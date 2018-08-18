// std::realloc

// Reallocates the given area of memory. It must be previously allocated
// with std::malloc(), std::calloc() or std::realloc() and not yet freed with std::free(),
// otherwise, the results are undefined

// The reallocation is doe by either:
// a) expanding or contracting the existing area pointed to by ptr, if possible.
//    The contents of the area remain unchaned up to the lesser of the new and old sizes.
//    If the area is expanded, the contents of the new part of the array are undefined.
// b) allocating a new memory block of size new_size bytes, copying memory area with size
//    equal the lesser of the new and the old sizes, and freeing the old block

// If there is not enough memory, the old memory block is not freed and null pointer is returned.
// If ptr is a null pointer, the behavior is the same as calling std::malloc(new_size)

// If new_size is zero, the behavior is implementation defined: null pointer may be returened
// (in which case the old memory block may or may not be freed) or some non-null pointer
// may be returned that may not be used to access storage

// Because reallocation may involve bytewise copying (regardless of whether it's to expand or
// to contact), only the object of TriviallyCopyable types are safe to access in the 
// preserved part of the memory block after a call to realloc.

#include <cstdlib>
#include <new>
#include <cassert>

class MallocDynamicBuffer
{
	char* p;
public:
	explicit MallocDynamicBuffer(std::size_t initial = 0) : p(nullptr) {
		resize(initial);
	}

	~MallocDynamicBuffer() { std::free(p); }
	void resize(std::size_t newSize) {
		if(newSize == 0) {
			std::free(p);
			p = nullptr;
		} else {
			if (void* mem = std::realloc(p, newSize))
				p = static_cast<char*>(mem);
			else
				throw std::bad_alloc();
		}
	}
	char& operator[](size_t n) { return p[n]; }
	char operator[](size_t n) const { return p[n]; }
};

int main()
{
	MallocDynamicBuffer buf1(1024);
	buf1[5] = 'f';
	buf1.resize(10);
	assert(buf1[5] == 'f');
	buf1.resize(1024);
	assert(buf1[5] == 'f');
}
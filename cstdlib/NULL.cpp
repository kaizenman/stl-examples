
// C

// In C, the macro NULL may have the type void*, but that is not allowed in C++
/* 
#ifndef NULL
# if defined __GNUG__ && \
    (__GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 8))
#  define NULL (__null)
# else
#  if !defined(__cplusplus)
#   define NULL ((void*)0)
#  else
#   define NULL (0)
#  endif
# endif
#endif
*/


// C++

//#define NULL 0
// since C++11
//#define NULL nullptr

// The macro NULL is an implementation-defined null pointer constant, which may be
// - an integer constant expression rvalue of integer type that evalueates to zero
// - an integer literal with value zero, or a prvalue of type std::nullptr_t

// A null pointer constant may be implicitly converted to any pointer type;
// such conversion results in the null pointer value of that type
// if a null pointer constant has integer type, it may be converted to a prvalue of type
// std::nullptr_t

// typedef decltype(nullptr) nullptr_t;



#include <cstdlib>
#include <type_traits>
#include <iostream>

class S;

int main()
{
	int * p = NULL;
	int * p2 = static_cast<std::nullptr_t>(NULL);
	void(*f)(int) = NULL;
	int S::*mp = NULL;
	void(S::*mfp)(int) = NULL;
	
	if (std::is_same_v<decltype(NULL), std::nullptr_t>) {
		std::cout << "NULL implemented with type std::nullptr_t\n";
	} else {
		std::cout << "NULL implemented using an integral type\n";
	}
}
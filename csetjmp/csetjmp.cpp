// setjmp()/longjmp() completely subvert stack unwinding and therefore exception handling as well as
// RAII (destructors in general)
// If any automatic object would be destroyed by a thrown exception transferring control to another
// (destination) point in the program, then a call to longjmp(jbuf, val) at the throw point that transfers
// control to the same (destination) point has undefined behavior.


// jmpbuf - execution context type

// setjmp - saves the context
// saves the current execution context into a variable env of type std::jmp_buf
// This variable can later be used to restore the current execution context by std::longjmp function.
// That is, when a call to std::longjmp function is made, the execution continues at the particular call site
// that constructed the std::jmp_buf variable passed to std::longjmp. In that case setjmp returns the value passed to
// std::longjmp
// the invocation of setjmp must appear only in one of the following contexts:
// - switch(setjmp(env)) {}
// - if(setjmp(env) > 0) {}
// - while(!setjmp(env)) {}
// - setjmp(env)
// If setjmp appears in any other context, the behavior is undefined


// std::longjmp - jumps to specified location
// Loads the execution context env saved by a previous call to setjmp. This function does not return.
// Control is transferred to the call site of the macro setjmp that set up env.
// That setmp then returns the value, passed as the status

// If the function that called setjmp has exited, the behavior is undefined (in other words, only long jumps up the
// call stack are allowed)
// No destructors for automatic objects are called. 
// If replacing of std::longjmp with throw and setjmp with catch would execute a non-trivial destructor for any
// automatic object, the behavior of such std::longjmp is undefined

// longjump is the mechanism used in C to handle unexpected error conditions where the function cannot return
// meaningfully. C++ generally uses exception handling for this purpose.

#include <iostream>
#include <csetjmp>

std::jmp_buf jump_buffer;

[[noreturn]] void a(int count)
{
    std::cout << "a(" << count << ") called\n";
    std::longjmp(jump_buffer, count + 1);       // setjmp() will return count+1
}

int main()
{
    volatile int count = 0;             // local variables must be volatile for setjmp 
    if (setjmp(jump_buffer) != 9) {
        a(count++);                     // This will cause setjmp() to exit
    }
}
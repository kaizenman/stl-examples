// The EXIT_SUCCESS and EXIT_FAILURE macros expand into integral expressions that can be
// used as arguments to the std::exit function (and, therefore, as the values to return
// from the main function), and indicate program execution status

// Under Unix and Unix-like operating systems, a process is started when its parent
// process executes a fork system call.
// The parent process may then wait for the child process to teminate,
// or may continue execution (possibly forking off other child processes).
// When the child process terminates ("dies"), either normally by calling exit, or
// abnormally due to a fatal error or signal (e.g., SIGTERM, SIGINT, SIGKILL), an 
// exit status is returned to the operating system and SIGCHLD signal is sent to
// the parent process. The exit status can then be retrueved by the parent process via
// the wait system call.

// System call is the programmatic way in which a computer program requests a service
// from the kernel of the operating system it is executed on. This may include
// hardware-related services (for example, accessing a hard disk drive), creation
// and execution of new processes, and communication with integral kernel services
// such as process scheduling.
// System calls provide an essential interface between a process and the operating system

// Generally, systems provide a library or API that sits between normal programs and the
// operating system.
// On Unix-like systems, that API is usually part of an implementation of the C library (libc), 
//    such as glibc, that provides wrapper functions for the system calls.
// On Windows NT, that API is part of the Native API, in the ntdll.dll library;

// The library's wrapper functionbs expose an ordinary function calling convension
// (a subroutine call on the assembly level) for using the system call.

// The primary function of the wrapper is to place all the argument to be passed to the
// system call in the appropriate processor registers and also setting a unique system call
// number for the kernel to call.

// The call to the library function itself does not cause a switch to kernel mode
// and usually a normal subroutine call (for example, a "CALL" assembly instruction)

// The actual system call does transfer control to the kernel.
// For example, in Unix-like systems, fork and execve are C library functions
// that turn in execute instructions that invoke the fork and exec system calls

// Typical way to implement system call is to use a software interrupt or trap
// For example, the x86 instruction set contains the instructions SYSCALL/SYSRET and SYSENTER/SYSEXIT
// There are also "fast" control transfer instructions that are designed to quickly transfer control
// to the kernel for a system call without the overhead of an interrupt (for example,
// the INT instruction, where the system call number was placed in the EAX register before interrupt
// 0x80 was executed)

// 	movl	$__NR_exit, %eax
//	int	$0x80


// std::exit causes normal program termination to occur.
// if any function registered with atexit or any destructor of static/thread-local object throws
// an exception, std::terminate is called
// all C streams are flushed and closed 

// destructors of objects with static storage duration are called in reverse order of completion 
// of their constructors or the completion of their dynamic initialization, and the functions 
// passed to std::atexit are called in reverse order they are registered (last one first).

// Stack is not unwound: destructors of variables with automatic storage duration are not called

// Returning from the main function, either by return statement or by reaching the end of the
// function performs the normal function termination (calls the destructors
// of the variables with automatic storage durations)
// and then executes std::exit, passing the argument of the return statement


#include <cstdlib>
#include <iostream>

class Static {
public:
	~Static()
	{
		std::cout << "Static dtor\n";
	}
};

class Local {
public:
	~Local()
	{
		std::cout << "Local dtor\n";
	}
};

Static static_variable; // dtor of this object *will* be called

void atexit_handler()
{
	std::cout << "atexit handler\n";
}

int main()
{
	Local local_variable; // dtor of this object will *not* be called
	const int result = std::atexit(atexit_handler); // handler will be called

	if (result != 0) {
		std::cerr << "atexit registration failed\n";
		return EXIT_FAILURE;
	}

	std::cout << "test\n";
	std::exit(EXIT_FAILURE);
}

// std::quick_exit
// Causes normal program termination to occur without completely cleaning the resources.
// Functions passed to std::at_quick_exit are called in reverse order of their registration.
// If an exception tries to propagate out of any of functions, std::terminate is called.
// After calling the registered functions, calls std::_Exit(exit_code)
// std::signal

// sets the handler for signal sig. The signal handler can be set so that default handling will occur, signal is
// ignored, or a user-defined function is called

// If a signal handler is executed as a result of call to std::raise(synchronously), then the execution of
// the handler is sequenced-after the invocation of std::raise and sequenced-before the return from it
// and runs on the same thread as std::raise.

// (C++14) Two accesses to the same object of type volatile std::sig_atomic_t do not result in a data race if
// both occur in the same thread, even if one or more occurs in a signal handler.

// POSIX requires that signal is thread-safe
// Signal handler are expected to have C linkage. It is implementation defined if a function with C++ linkage
// can be used as a signal handler


// std::raise

// Sends signal sig to the program. The signal handler (specified using the std::signal() function) is invoked.
// If the user-defined signal handling strategy is not set using std::signal() yet, it is implementation-defined
// whether the signal will be ignored or default handler will be invoked.

// Return value is 0 upon success, non-zero value on failure

// SIGABRT  - abnormal termination condition, as is e.g. initiated by std::abort()
// SIGFPE   - erroneous arithmetic operation such as divide by zero
// SIGILL   - invalid program image, such as invalid instruction
// SIGINT   - external interrupt, usually initiated by the user
// SIGSEGV  - invalid memory access (segmentation fault)
// SIGTERM  - termination request, sent to the program

// additional signal names are specified by POSIX


// std::sig_atomic_t
// An integer type which can be accessed as an atomic entity even in the presence of asynchronous interrupts
// made by signals
// Until C++11, which introduced std::atomic and std::atomic_signal_fence, about the only thing a strictly
// conforming program could do in a signal handler was to assign a value to a volatile static std::sig_atomic_t
// variable and promptly return


// Does signal() cause any performance loss?
// If your time critical process catches signals, there is no "special" time wasting, Indeed, the kernel holds a
// table of signals and actions for your process which it has to walk through if a signal was send.
// But every way of sending a message to a process or invoking a handler needs time

// Nearly every system call can be interrupted if the signal arrives

// if you have many signals you pass to your process, this may slow down your application a lot, because you
// have always to check for EINTR with go again into the system call. And every system call is a bit expensive.

// SIGABRT, SIGSEGV and SIGILL are typically used only for seldom exceptions.
// Avoid using these signals frequently for own IPC. That can be done but is very bad design.
// For user IPC there are better signaal na


#include <csignal>
#include <iostream>

namespace {
    volatile std::sig_atomic_t gSignalStatus;
}

void signal_handler(int signal)
{
    gSignalStatus = signal;
}

int main()
{
    std::signal(SIGINT, signal_handler);

    std::cout << "SignalValue: " << gSignalStatus << '\n';
    std::cout << "Sending signal " << SIGINT << '\n';

    std::raise(SIGINT);
    std::cout << "SignalValue: " << gSignalStatus << '\n';
}
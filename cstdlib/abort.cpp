#include <cstdlib>

// std::abort causes abnormal program termination unless SIGABRT is being caught
// by a signal handler passed to std::signal and the handler does not return

// Destructors of variables with automatic, thread local, and static storage
// durations are not called.

// Functions registered with std::atexit() and std::at_quick_exit() are not called
// Whether open resources such as files are closed is implementation defined.

#include <csignal>
#include <iostream>

class Tester {
public:
	Tester() { std::cout << "Tester ctor\n"; }
	~Tester() { std::cout << "Tester dtor\n"; }
};

Tester static_tester; // Destructor not called

void signal_handler(int signal)
{
	if (signal == SIGABRT) {
		std::cerr << "SIGABRT received\n";
	} else {
		std::cerr << "Unexpected signal " << signal << " received\n";
	}
	std::_Exit(EXIT_FAILURE);
}

int main()
{
	Tester automatic_tester; // Destructor not called

	auto previous_handler = std::signal(SIGABRT, signal_handler);
	if (previous_handler == SIG_ERR) {
		std::cerr << "Setup failed\n";
		return EXIT_FAILURE;
	}

	std::abort();
	std::cout << "This code is unreachable\n";
}	
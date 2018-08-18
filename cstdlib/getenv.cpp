// std::getenv

// Searches the environment list provided by the host environment (the OS),
// for a string that matches the C string pointed to be env_var and
// returns a pointer to the C string that is associated with the matched 
// environment list member

#include <iostream>
#include <cstdlib>

int main()
{
	if (const char* env_p = std::getenv("PATH"))
		std::cout << "Your PATH is: " << env_p << '\n';
}
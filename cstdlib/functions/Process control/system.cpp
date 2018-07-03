
// std::system

// Calls the host environment's command processor
// (e.g. /bin/sh, cmd.exe, command.com) with the parameter command.
// Returns an implementation-defined value (usually the value that the
// invoked program returns).

// If a command is a null pointer, checks if the host environment has a command
// processor and returns a nonzero value if and only if the command processor
// exists

// [command]  - character string identifying the command to be run in the
// command processor. If a null pointer is given, command processor is checked
// for existence

#include <cstdlib>
#include <fstream>
#include <iostream>

int main()
{
	std::system("start \"\" \"%PROGRAMFILES%\\Git\\bin\\sh.exe\" \
		--login -x -c \"ls -l >test.txt\"");
	std::cout << std::ifstream("test.txt").rdbuf();
}
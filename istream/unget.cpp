#include <sstream>
#include <iostream>

// Makes the most recently extracted character available again.

// First clears eofbit

// After constructing and checking the sentry object, if any
// ios_base::iostate flags are set, the function sets failbit and returns.
// Otherwise, calls rdbuf()->sungetc()
// If rdbuf()->sungetc() returns Traits::eof(), calls setstate(badbit).
// In any case, sets the gcount() counter to zero

int main()
{
    std::istringstream s1("Hello, world.");
    char c1 = s1.get();

    if (s1.unget())
    {
        char c2 = s1.get();
        std::cout << "Got: " << c1 << " got again: " << c2 << '\n';
    }
}
// std::basic_istream::peek

// After constructing and testing the sentry object,
// reads the next character from the input stream without extracting it.


#include <sstream>
#include <iostream>

int main()
{
    std::istringstream s1("Hello, world");
    char c1 = s1.peek();
    char c2 = s1.get();
    std::cout << "Peeked: " << c1 << " got: " << c2 << '\n';
}
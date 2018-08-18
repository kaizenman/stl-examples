// std::basic_istream::sentry

// An object of class sentry is constructed in local scope
// at the beginning of each member function of
// std::basic_istream that performs input (both formatted
// and unformatted). Its constructor prepares the input
// stream: checks if the stream is already in a failed state,
// flushes the tie()'d output streams, skips leading whitespace
// performed in the destructor, so that it is guaranteed to happen
// if exceptions are thrown during input



#include <iostream>
#include <sstream>

struct Foo
{
    char n[5];    
};

std::istream& operator>>(std::istream& is, Foo& f)
{
    std::istream::sentry s(is);
    if (s)
        is.read(f.n, 5);
    return is;
}

int main()
{
    std::string input = "    abcde";
    std::istringstream stream(input);

    Foo f;
    stream >> f;
    std::cout.write(f.n, 5);
    std::cout << '\n';
}
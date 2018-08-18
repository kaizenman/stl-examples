
// make_error_condition

// creates an error condition for an errc value e. Set the error code to int(e) and error category to std::generic_categorys

#include <system_error>
#include <string>
#include <iostream>

int main()
{
    auto err = std::make_error_condition(std::errc::invalid_argument);
    std::cout << err.message() << '\n';
}
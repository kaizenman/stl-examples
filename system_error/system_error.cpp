// <system_error>

// Class------------
// error_category               base class for error categories
// error_condition              holds a portable error code
// errc                         the std::error_condition enumeration listing all standard <cerno> macro constants
// error_code                   holds a platform-dependent error code
// system_error                 exception class used to report conditions that have an error_code
// is_error_code_enum           identifies a class as an error_code enumeration
// is_error_condition_enum      identifies an enumeration as an std::error_condition

// Functions--------
// generic_category             identifies the generic error category
// system_category              identifies the operating system error category
// operator==, !=, <            compares two error codes
// operator<<                   outputs the value and the category name to an output stream
// make_error_code              constructs an std::errc error code, equivalent to std::error_code(static_cast<int>(e), std::generic_category())
// make_error_condition         constructs an std::errc error condition

#include <system_error>

int main()
{

}
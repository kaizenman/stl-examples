// std::atof

// iterprets a floating point value in a byte string pointed to by str.

// Function discards any whitespace characters (as determined by std::isspace())
// until first non-whitespace character is found. Then it takes as many characters
// as possible to form a valid floating-point representation and converts them to a 
// floating-point value.

#include <cstdlib>
#include <iostream>

int main()
{
	std::cout << std::atof("0.0000000123") << '\n'
	          << std::atof("0.012") << '\n'
	          << std::atof("15e16") << '\n'
	          << std::atof("-0x1afp-2") << '\n'
	          << std::atof("inF") << '\n'
	          << std::atof("Nan") << '\n';
}

// std::atoi, std::atol, std::atoll

// Iterprets an integer value in a byte string pointed to by str

// Discards any whitespace characters until the first non-whitespace
// character is found, then takes as many characters as possible to form
// a valid integer number representation and converts them to an integer value.

// The valid integer value consists of the following parts:
// - (optional) plus or minus sign
// - numeric digits

// If the convefrted value falls out of range of corresponging return type,
// the return value is undefined. If no conversion can be performed, 0 is returned

#include <iostream>
#include <cstdlib>

int main()
{
	const char *str1 = "42";
	const char *str2 = "3.14159";
	const char *str3 = "-41447 with words";
	const char *str4 = "words and 2";

	int num1 = std::atoi(str1);
	int num2 = std::atoi(str2);
	int num3 = std::atoi(str3);
	int num4 = std::atoi(str4);

	std::cout << "std::atoi(\"" << str1 << "\") is " << num1 << '\n';
	std::cout << "std::atoi(\"" << str2 << "\") is " << num2 << '\n';
	std::cout << "std::atoi(\"" << str3 << "\") is " << num3 << '\n';
	std::cout << "std::atoi(\"" << str4 << "\") is " << num4 << '\n';
} 
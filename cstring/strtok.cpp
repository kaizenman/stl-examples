// std::strtok

// Finds the next token in a null-terminated byte string pointed to by str.
// The separator characters are identified by null-terminated byte string pointed to by delim

// This function is designed to be called multiples times to obtain successive tokens from the same string

// This function is destructive: it writes the '\0' characters in the elements of the string str.
// In particular, a string literal cannot be used as the first argument of strtok
// Each call to this function modifies a static variable: it is not thread safe
// Unlike most other tokenizers, the delimiters in strtok can be different for each subsequent token, and can even
// depend on the contents of the previous tokens

// if str != NULL, the call is treated as the first call to strtok for this particular string. The function
//  searches for the first character which is not contained in delim. the function then returns the pointer to the
//  beginning of the token
// if str == NULL, the call is treated as a subsequent calls to strtok: the function continues from where it left
//  in previos invocation. The behavior is the same as if the previously store pionter is passed as str


#include <cstring>
#include <iostream>

int main()
{
    char input[100] = "A bird came down the walk";
    char *token = std::strtok(input, " ");
    while(token != NULL) {
        std::cout << token << '\n';
        token = std::strtok(NULL, " ");
    }
}
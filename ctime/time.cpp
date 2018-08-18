// std::time

// Returns the current calendar time encoded as a std::time_t object
// and also stores it in the object pointed to by arg,
// unless arg is a null pointer
 
// Returns
// on success calendar time encoded as std::time_t object
// on error (std::time_t)(-1)

// localtime - converts time since epoch to calendar time expressed as local time

// asctime - converts a tm object to a textual representation
// strftime - converts a tm object to custom textual representation
// wcsftime - converts a tm object to custom wide string textual representation
// gmtime - converts time since epoch to calendar time expressed as Universal Coordinated Time
// mktime - converts calendar time to time since epoch



#include <ctime>
#include <iostream>

int main()
{
    std::time_t result = std::time(nullptr);
    std::cout << std::asctime(std::localtime(&result))
              << result << " seconds since the Epoch\n";
                           
}
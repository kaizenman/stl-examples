

// exception                base class for exceptions thrown by the stl components
// nested_exception         a mixin type to capture and store current exceptions
// bad_exception            exception thrown when std::current_exception fails to copy the exception object


// unexpected_handler
// terminate_handler
// exception_ptr

// make_exception_ptr
// current_exception
// rethrow_exception
// throw_with_nested
// rethrow_if_nested
// terminate
// get_terminate
// set_terminate


#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

void handle_eptr(std::exception_ptr eptr)
{
    try {
        if (eptr) {
            std::rethrow_exception(eptr);
        }
    } catch(const std::exception& e) {
        std::cout << "Caught exception \"" << e.what() << "\"\n";
    }
}

int main()
{
    std::exception_ptr eptr;
    try {
        std::string().at(1); // this generates an std::out_of_range
    } catch(...) {
        eptr = std::current_exception(); // capture
    }
    handle_eptr(eptr);
} // destructor for std::out_of_range called here, when the eptr is destructed
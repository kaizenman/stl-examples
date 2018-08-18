// std::error_condition

// Like std::error_code, it is uniquely identified by an integer value and a std::error_category
// Unlike std::error_code, the value is not platform-dependent

// A typical implementation holds one integer data member (the value) and a pointer to an std::error_category
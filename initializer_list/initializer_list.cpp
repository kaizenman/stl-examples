
// std::initializer_list


// std::begin
// std::end

// An initializer list forces so-called value initialization
// which means that even local variables of fundamental data types,
// which usually have an undefined initial value, are initialized by zero (or nullptr)

// However, that narrowing initializations - those that reduce precision or where
// the supplied values gets modified - are not possible with braces.

// When there are construtors for both a specific number of arguemnts and an initializer list,
// the version with the initializer list is preferred


// Because of initializer list, explicit now also becomes relevant for constructors
// taking more than one argument.

// Now you can disable automatic type conversions from multiple values, which is also
// used when an initialization uses the = syntax;

#include <initializer_list>

void print(std::initiazlier_list<int> vals)
{
    for (auto p = vals.begin(); p!= vals.end(); ++p) {
        std::cout << *p << "\n";
    }
}
int main()
{
    int values[] {1, 2, 3};
    print ({12,3,5,7,11,13,17});
}
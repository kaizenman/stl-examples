// tuple                    - implements fixed isze container, which holds
//                            elements of possibly different types

// tuple_size               - obtains the size of tuple at compile time

// tuple_element            - obtains the type of the specified element

// std::uses_allocator      - specializes the std::uses_allocator type trait



// ignore


// make_tuple
// tie
// forward_as_tuple
// tuple_cat
// std::get(tuple)
// std::swap
// apply
// make_from_tuple

#include <tuple>
#include <iostream>
#include <string>
#include <stdexcept>

std::tuple<int, int> foo_tuple()
{
    return {1, -1};
}

std::tuple<int, int> foo_tuple2()
{
    return std::make_tuple(1, -1);
}

std::tuple<double, char, std::string> get_student(int id)
{
    if (id == 0) return {3.8, 'A', "Lisa Simpson"};
    if (id == 1) return {2.9, 'C', "Milhouse Van Houten"};
    if (id == 2) return {1.7, 'D', "Ralph Wiggum"};
    throw std::invalid_argument("id");
}


int main()
{
    auto student0 = get_student(0);
    std::cout << "ID: 0, "
              << "GPA: " << std::get<0>(student0) << ", "
              << "grade: " << std::get<1>(student0) << ", "
              << "name: " << std::get<2>(student0) << '\n';


    double gpa1;
    char grade1;
    std::string name1;

    std::tie(gpa1, grade1, name1) = get_student(1);
    std::cout << "ID: 1, "
              << "GPA: " << gpa1 << ", "
              << "grade: " << grade1 << ", "
              << "name: " << name1 << '\n';

    // C++17 structured bindings
    auto [gpa2, grade2, name2] = get_student(2);
    std::cout << "ID: 2, "
              << "GPA: " << gpa2 << ", "
              << "grade: " << grade2 << ", "
              << "name: " << name2 << '\n';    
}
// std::list

// A container that supports constant time insertion and removal of elements 
// from anywhere in the container

// Fast random access is not supported
// It is usually implemented as a doubly-linked list

// Compared to std::forward_list this container provides bidirectional iteration capability
// while being less space efficient

#include <algorithm>
#include <iostream>
#include <list>

int main()
{
    std::list<int> l = {7, 5, 16, 8};

    l.push_front(25);
    l.push_back(14);

    auto it = std::find(l.begin(), l.end(), 16);
    if (it != l.end()) {
        l.insert(it, 42);
    }

    for (int n : l) {
        std::cout << n << '\n';
    }
}
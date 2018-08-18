// reset
// Replaces the managed object


// To replace the managed object while supplying a new deleter as well,
// move assignment operator may be used.
// A test for self-reset, i.e whether ptr point to an object already managed by *this,
// is not performed, except where provided as a compiler extension or as a debugging assert.
// Note that code such as p.reset(p.release()) does not involve self-reset, only code like p.reset(p.get()) does

#include <iostream>
#include <memory>

struct Foo
{
    Foo() { std::cout << "Foo...\n"; }
    ~Foo() { std::cout << "~Foo...\n"; }
};

struct D {
    void operator() (Foo* p) {
        std::cout << "Calling delete for Foo object...\n";
        delete p;
    }
};

int main()
{
    std::cout << "Creating new Foo...\n";
    std::unique_ptr<Foo, D> up(new Foo(), D()); // up owns the Foo pointer(deleter D)

    std::cout << "Replace owned Foo with a new Foo...\n";
    up.reset(new Foo()); // calls deleter for the old one

    std::cout << "Release and delete the owned Foo...\n";
    up.reset(nullptr);
}
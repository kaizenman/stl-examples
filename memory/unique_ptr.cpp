// unique_ptr


// smart pointer that owns and manages another object through a pointer
// and disposes of that object when the unique_ptr goes out of scope

// Only non-const unique_ptr can transfer the ownership of the managed object to
// another unique_ptr

// If an object's lifetime is managed by a const std::unique_ptr, it is limited
// to the scope in which the pointer was created



// Modifiers----
// release       returns a pointer to the managed object and releases the ownership
// reset         replaces the managed object
// swap          swaps the managed objects

// Observers----
// get           returns a pointer to the managed object
// get_deleter   returns the deleter that is used for destruction of the managed object
// operator bool checks if there is an associated managed object

// make_unique   creates a unique pointer that manages a new object


#include <iostream>
#include <vector>
#include <memory>
#include <cstdio>
#include <fstream>
#include <cassert>
#include <functional>

struct B {
    virtual void bar() { std::cout << "B::bar\n"; }
    virtual ~B() = default;
};

struct D : B
{
    D() { std::cout << "D::D\n"; }
    ~D() { std::cout << "D::~D\n"; }
    void bar() override { std::cout << "D::bar\n"; }
};

std::unique_ptr<D> pass_through(std::unique_ptr<D> p)
{
    p->bar();
    return p;
}

void close_file(std::FILE* fp)
{
    std::fclose(fp);
}

int main()
{
    std::cout << "unique ownership semantics demo\n";

    {
        auto p = std::make_unique<D>();
        auto q = pass_through(std::move(p));
        assert(!p); // now p owns nothing and holds a null pointer
        q->bar();   // and q owns the D object
    } // ~D() called here

    std::cout << "Runtime polymorphism demo\n";
    {
        // p is a unique_ptr that owns a D as a pointer to base
        std::unique_ptr<B> p = std::make_unique<D>();
        p->bar();

        std::vector<std::unique_ptr<B>> v;
        v.push_back(std::make_unique<D>());
        v.push_back(std::move(p));
        v.emplace_back(new D);

        for(auto& p: v) p->bar();
    }

    std::cout << "Custom deleter demo\n";
    std::ofstream("demo.txt") << 'x'; // prepare the file to read
    {
        std::unique_ptr<std::FILE, decltype(&close_file)> fp(std::fopen("demo.txt", "r"), &close_file);
        if (fp) // fopen could have failed; in which case fp holds a null pointer
            std::cout << (char) std::fgetc(fp.get()) << '\n';   
    } // fclose() called here, but only if FILE* is not a null pointer (if fopen succeeded)

    std::cout << "Custom lambda-expression deleter demo\n";
    {
        std::unique_ptr<D, std::function<void(D*)>> p(new D, [](D* ptr) { std::cout << "destroying from a custom deleter...\n"; delete ptr; });
        p->bar();
    }

    std::cout << "Array form of unique_ptr demo\n";
    {
        std::unique_ptr<D[]> p{new D[3]};
    }
}   
// shared_ptr

// is a smart pointer that retains shared ownership of an object through a pointer
// Several shared_ptr objects may own the same object
// The object is destroyed and its memory deallocated when
// - the last remaining shared_ptr owning the object is destroyed
// - the last remaining shared_ptr owning the object is assigned another pointer via operator= or reset()

// The ownership of an object can only be shared with another shared_ptr by copy constructing or
// copy assigning its value to another shared_ptr
// Constructing a new shared_ptr using the raw underlying pointer owned by another shared_ptr leads
// to undefined behavior


// In a typical implementation, std::shared_ptr holds only two pointers
// - the stored pointer (one returned by get())
// - a pointer to control block

// The control block is a dynamically-allocated object that holds:
// - either a pointer to the managed object or the managed object itself
// - the deleter
// - the allocator
// - the number of shared_ptrs that own the managed object
// - the number of weak_ptrs that refer to the managed object

// When shared_ptr is created by calling std::make_shared or std::allocate_shared, the memory
// for both the control block and the managed object is created with a single allocation.
// The managed object is constructed in-place in a data member of the control block.

// When shared_ptr is created via one of the shared_ptr constructors, the managed object and the
// control block must be allocated separately. In this case, the control block stores a pointer
// to the managed object.

#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include <mutex>

struct Base
{
    Base() { std::cout << " Base::Base()\n"; }
    ~Base() { std::cout << " Base::~Base()\n"; }
};

struct Derived : public Base
{
    Derived() { std::cout << " Derived::Derived()\n"; }
    ~Derived() { std::cout << " Derived::~Derived()\n"; }
};

void thr(std::shared_ptr<Base> p)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::shared_ptr<Base> lp = p; // thread-safe, even though the 
                                  // shared use_count is incrementedv
    {
        static std::mutex io_mutex;
        std::lock_guard<std::mutex> lk(io_mutex);
        std::cout << "local pointer in a thread:\n"
                  << " lp.get() = " << lp.get()
                  << ", lp.use_count() = " << lp.use_count() << '\n';
    }
}

int main()
{
    std::shared_ptr<Base> p = std::make_shared<Derived>();
    std::cout << "Created a shared Derived (as a pointer to Base)\n"
              << " p.get() = " << p.get()
              << ", p.use_count() = " << p.use_count() << '\n';

    std::thread t1(thr, p), t2(thr, p), t3(thr, p);

    p.reset();
    std::cout << "Shared ownership between 3 threads and released\n"
              << "ownership from main:\n"
              << " p.get() = " << p.get()
              << ", p.use_count() = " << p.use_count() << '\n';

    t1.join();
    t2.join();
    t3.join();

    std::cout << "All threads completed, the last one deleted Derived\n";
}
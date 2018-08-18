// weak_ptr

// smart pointer that holds a non-owning ("weak") reference to an object that is managed
// by shared_ptr. It must be converted to std::shared_ptr in order to access the references object


// Like std::shared_ptr, a typical implementation of weak_ptr stores two pointers:
// - a pointer to the control block
// - the stored pointer of the shared_ptr it was constructed from
// A separated stored pointer is necessary to ensure that converting a shared_ptr to weak_ptr
// and then back works correctly, even for aliased shared_ptrs. It is not possible to access the stored
// pointer in a weak_ptr without locking it into a shared_ptr

#include <iostream>
#include <memory>

std::weak_ptr<int> gw;

void observe()
{
    std::cout << "use_count == " << gw.use_count() << ": ";
    if (auto spt = gw.lock()) {
        std::cout << *spt << '\n';
    }
    else {
        std::cout << "gw is expired\n";
    }
}

int main()
{
    {
        auto sp = std::make_shared<int>(42);
        gw = sp;

        observe();
    }

    observe();
}
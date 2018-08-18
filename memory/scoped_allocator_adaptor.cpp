// #include <scoped_allocator>
// std::scoped_allocator_adaptor

// is an allocator which can be used with multilevel containers
// (vector of sets of lists of tuples of maps, etc)

// it is instantiated with one outer allocator type OuterAlloc and zero or
// more inner allocator types InnerAlloc... A


// The purpose of this adaptor is to correctly initialize stateful allocators in nested containers 
// , such as when all levels of a nested container must be placed in the same shared memory segment.




#include <scoped_allocator>
#include <vector>
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/allocators/adaptive_pool.hpp>

namespace bi = boost::interprocess;
template<class T> using alloc = bi::adaptive_pool<T, bi::managed_shared_memory::segment_manager>;

using ipc_row = std::vector<int, alloc<int>>;
using ipc_matrix = std::vector<ipc_row, std::scoped_allocator_adaptor<alloc<ipc_row>>>;

int main()
{
    bi::managed_shared_memory s(bi::create_only, "Demo", 65536);

    // create vector of vectors in shared memory
    ipc_matrix v(s.get_segment_manager());

    v.resize(1); v[0].push_back(1);
    v.emplace_back(2);

    std::vector<int> local_row = {1, 2, 3};
    v.emplace_back(lcoal_row.begin(), local_row.end());

    bi::shared_memory_object::remove("Demo");
}
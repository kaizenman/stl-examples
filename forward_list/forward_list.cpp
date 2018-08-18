// std::forward_list

// singly-linked list

// the forward_list class template has been designed with efficiency in mind
// By design, it is as efficient as a simple handwritten C-style singly-linked list
// In fact is the only standard container to deliberately lack a size member function for efficiency considerations

// Due to its nature as a linked list, having a size member that takes constant time would require
// it to keep an internal counter for its size (as list does). This would consume some extra storage and
// make insertion and removal operations slightly less efficient.

// To obtain the size of a forward_list object, you can use the distance algorithm with its begin and end,
// which is an operation that takes linear time


#include <forward_list>

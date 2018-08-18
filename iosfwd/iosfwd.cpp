#include <iosfwd>

// forward declarations of the input/output library

// use in your own headers
// iostream headers themselves are large, complex and slow to compile against

/*
# The following commands create a source file that includes a single header
# file (on stdout), preprocess it with g++ -E, and then count how many lines
# are in the resulting preprocessed output
$ echo '#include <iosfwd>' | g++ -E -xc++ - | wc
    2598    6534   57875
$ echo '#include <iostream>' | g++ -E -xc++ - | wc
   25631   59613  631998
*/

// A file that includes <iosfwd>, the compiler has to process 2598 lines of code
// from various header files, whereas a file that includes <iostreaM>
// has to process a whopping 25631 lines of code. That's before compiling the
// actual code you care about in your source file
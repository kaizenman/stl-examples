// std::basic_istream::ignore

// extracts and sicards characters from the input stream
// until and including delim

// After constructing and checking the sentry object, it
// extracts characters from the stream and discards them
// until any one of the following conditions occurs:
// - count characters were extracted. This test is disabled
//   in the special case when count equals 
//   std::numeric_limits<std::streamsize>::max()
// - end of file condition occurs in the input sequence,
//   in which case the function calls setstate(eofbit)
// - the next available character c in the input sequence
//   is delim. The delimiter character is extracted and discarded
//   This test is disabled if delim is Traits::eof()


#include <iostream>
#include <sstream>
#include <limits>

int main()
{
    std::istringstream input("1\n"
                       "some non-numeric input\n"
                       "2\n");

    for(;;) {
        int n;
        input >> n;

        if (input.eof() || input.bad()) {
            break;
        } else if (input.fail()) {
            input.clear();
            // skip bad input
            input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            std::cout << n << '\n';
        }
    }

}
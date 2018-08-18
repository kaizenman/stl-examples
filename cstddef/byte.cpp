#include <cstddef>
#include <iostream>

// the byte type (enum)

int main() {

    std::byte b1{0x3F};
    std::byte b2{0b1111'0000};

    std::byte b3[4] {b1, b2, std::byte{1}};

    if (b1 == b3[0]) {
        b1 <<= 1;
    }

    std::cout << std::to_integer<int>(b1) << '\n';
}   
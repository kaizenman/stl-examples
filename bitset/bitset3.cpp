#include <iostream>
#include <bitset>

int main()
{
    std::bitset<8> b1(42);
    for (std::size_t i = 0; i < b1.size(); ++i) {
        std::cout << "b1[" << i << "]: " << b1[i] << '\n';
    }

    b1[0] = true; // modifies the first bit through bitset::reference
    std::cout << "After setting bit 0, the bitset holds " << b1 << '\n';
}
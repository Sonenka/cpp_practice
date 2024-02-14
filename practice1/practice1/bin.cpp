#include <iostream>
#include "bin.hpp"

//Converts a decimal number into its binary representation.
void bin(int n) {
    long res = 0;
    if (n > 1) {
        bin(n / 2);
    }
    std::cout << n % 2;
}
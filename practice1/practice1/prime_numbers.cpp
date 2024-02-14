#include <iostream>
#include "prime_numbers.hpp"

//Prints prime numbers up to 100.
void prime_numbers() {
    int f = 0;
    for (int i = 2; i < 100; i++) {
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                f = 1;
                break;
            }
        }

        if (f == 1) {
            f = 0;
            continue;
        }

        std::cout << i << " ";
    }
}
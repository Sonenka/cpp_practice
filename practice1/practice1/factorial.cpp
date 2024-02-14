#include "factorial.hpp"

//Returns the factorial of a given number.
long factorial(int n) {
    long res = 1;

    for (int i = 1; i <= n; ++i) {
        res *= i;
    }

    return res;
}
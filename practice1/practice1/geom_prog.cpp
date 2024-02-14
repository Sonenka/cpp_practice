#include <cmath>
#include "geom_prog.hpp"

//Returns the sum of a geometric progression.
double geom_prog(int a, double q, int e) {
    double res = 0;
    for (int i = 0; i < e; i++) {
        res += a * pow(q, 2 * i);
    }

    return res;
}
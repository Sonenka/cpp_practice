#include <iostream>
#include "quad_eq.hpp"

//Calculates the discriminant of a quadratic equation.
double disc(double a, double b, double c) {
    return b * b - 4 * a * c;
}

//Solves a quadratic equation and prints its roots.
void quad_eq(double a, double b, double c) {
    double d = disc(a, b, c);

    if (d < 0) {
        std::cout << "No roots";
    }

    else if (d == 0) {
        int x = -b / (2 * a);
        std::cout << x;
    }

    else {
        int x1, x2;
        x1 = (-b + sqrt(d)) / (2 * a);
        x2 = (-b - sqrt(d)) / (2 * a);

        std::cout << x1 << " " << x2;
    }
}
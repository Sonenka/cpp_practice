#include <iostream>

#include "factorial.hpp"
#include "quad_eq.hpp"
#include "prime_numbers.hpp"
#include "bin.hpp"
#include "geom_prog.hpp"
#include "isChar.hpp"

#define TASK_2


int main() {
    std::cout << "Choose the task:\n";
    std::cout << "1. Factorial\n2. Quadratic equation\n3. Prime numbers\n4. Dec to Bin\n5. Geometric progression\n6. IsChar\n";

    int task;
    std::cin >> task;

    if (task == 1) {
        int n;
        std::cin >> n;

        std::cout << factorial(n);

        return 0;
    }

    else if (task == 2) {
        double a, b, c;
        std::cin >> a >> b >> c;

        quad_eq(a, b, c);

        return 0;
    }

    else if (task == 3) {
        prime_numbers();

        std::cout << std::endl;

        return 0;
    }

    else if (task == 4) {
        int n;
        std::cin >> n;

        bin(n);

        return 0;
    }

    else if (task == 5) {
        int a, e;
        double q;
        std::cin >> a >> q >> e;

        std::cout << geom_prog(a, q, e);

        return 0;
    }

    else if (task == 6) {
        char ch;
        std::cin >> ch;

        std::cout << std::boolalpha << isChar(ch);

        return 0;
    }

    else {
        std::cout << "Wrong task number.\n";
    }
}
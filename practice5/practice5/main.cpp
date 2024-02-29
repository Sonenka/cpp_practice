#include <iostream>
#include "dynarray.hpp"
#include "vecnd.hpp"
#include "tests.hpp"
#include "mat2d.hpp"
#include "system.hpp"


long DynArray::obj_alive = 0;

int main() {
	vecnd_test();
    mat2d_test();
    system_test();

    return 0;
}


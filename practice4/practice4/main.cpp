#include <iostream>
#include "vec3d.hpp"
#include "dynarray.hpp"
#include "examples.hpp"

long DynArray::DynArray::obj_alive = 0;

int main() {
    example_vec3d();

    example_dynarray();

    return 0;
}

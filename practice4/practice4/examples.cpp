#include <iostream>
#include "examples.hpp"

void example_vec3d() {
    std::cout << "Working with vec3d\n";
    Vec3D vec1(1, 1.5, 2), vec2(0.5, 4, 2);
    double dot_prod = vec1 * vec2;
    std::cout << dot_prod << "\n";

    Vec3D cross_prod = vec1 & vec2;
    std::cout << cross_prod.x << ' ' << cross_prod.y << ' ' << cross_prod.z << "\n";
}

void example_dynarray() {
    std::cout << std::endl;
    std::cout << "Working with DynArray\n";
    DynArray arr1;
    arr1.append(1.0);
    arr1.append(2.0);
    arr1.append(3.0);

    DynArray arr2(3);
    arr2.append(4.0);
    arr2.append(5.0);
    arr2.append(6.0);

    arr1 << 2;
    arr2 >> 1;

    DynArray arr3 = arr1 + arr2;

    std::cout << "Array 1 elements:" << "\n";
    for (int i = 0; i < arr1.size(); i++) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Array 2 elements:" << "\n";
    for (int i = 0; i < arr2.size(); i++) {
        std::cout << arr2.get(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "Array 3 elements (after concatenation):" << "\n";
    arr3.printArray();

    DynArray arr4;
    arr4 = arr3 << 1;
    arr4[0] = 100;
    std::cout << "Array 4 elements:" << "\n";
    arr4.printArray();

    std::cout << "Number of DynArray objects alive: " << DynArray::obj_alive << std::endl;

}
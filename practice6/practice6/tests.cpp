#include "dynarray.hpp"
#include "mat2d.hpp"
#include "queue.hpp"
#include "tests.hpp"
#include "vecnd.hpp"
#include <iostream>
#include <vector>

void dynarray_test() {
    std::cout << "DYNARRAY_TEST\n";
    DynArray<double> arr1;
    arr1.append(1.0);
    arr1.append(2.0);
    arr1.append(3.0);

    DynArray<double> arr2(3);
    arr2.append(4.0);
    arr2.append(5.0);
    arr2.append(6.0);

    arr1 << 2;
    arr2 >> 1;

    DynArray<double> arr3 = arr1 + arr2;

    std::cout << "Array 1 elements:" << "\n";
    arr1.printArray();

    std::cout << "Array 2 elements:" << "\n";
    arr2.printArray();

    std::cout << "Array 3 elements (after concatenation):" << "\n";
    arr3.printArray();
    
    DynArray<double> arr4 = arr3 << 1;
    arr4[0] = 100;
    std::cout << "Array 4 elements:" << "\n";
    arr4.printArray();

    std::cout << "Number of DynArray objects alive: " << DynArray<double>::obj_alive << std::endl;
    std::cout << std::endl;
}

void queue_test() {
    std::cout << "QUEUE_TEST\n";
    Queue<int> queue;

    std::cout << "Is the queue empty? " << (queue.empty() ? "Yes" : "No") << std::endl;

    queue.push(1);
    queue.push(2);
    queue.push(3);

    std::cout << "Queue size: " << queue.getSize() << std::endl;

    std::cout << "Popping elements from the queue: ";
    while (!queue.empty()) {
        std::cout << queue.pop() << " ";
    }
    std::cout << std::endl;

    std::cout << "Is the queue empty? " << (queue.empty() ? "Yes" : "No") << std::endl;
    std::cout << std::endl;
}

void vecnd_test() {
    std::cout << "VECND_TEST" << std::endl;
    VecND<double> vec1(4);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 3;
    vec1[3] = 4;

    VecND<double> vec2 = vec1;

    VecND<double> vec3(4);
    vec3[0] = 10;
    vec3[1] = 20;
    vec3[2] = 30;
    vec3[3] = 40;

    VecND<double> vecSum = vec1 + vec3;
    VecND<double> vecMult = vec1 * vec3;

    std::cout << "Vector 1: ";
    vec1.printVec();

    std::cout << "Vector 2: ";
    vec2.printVec();

    std::cout << "Vector 3: ";
    vec3.printVec();

    std::cout << "Vector Sum: ";
    vecSum.printVec();

    std::cout << "Vector Mult: ";
    vecMult.printVec();
    std::cout << std::endl;
}

void mat2d_test() {
    std::cout << "MAT2D_TEST" << std::endl;
    Mat2D<double> matrix1(2, 2);
    matrix1[0][0] = 1;
    matrix1[0][1] = 2;
    matrix1[1][0] = 3;
    matrix1[1][1] = 4;

    Mat2D<double> matrix2(2, 2);
    matrix2[0][0] = 5;
    matrix2[0][1] = 6;
    matrix2[1][0] = 7;
    matrix2[1][1] = 8;

    std::cout << "Matrix 1:" << std::endl;
    matrix1.printMat();

    std::cout << "Matrix 2:" << std::endl;
    matrix2.printMat();

    Mat2D<double> sumMatrix = matrix1 + matrix2;
    std::cout << "Sum of Matrices:" << std::endl;
    sumMatrix.printMat();

    Mat2D<double> productMatrix = matrix1 * matrix2;
    std::cout << "Product of Matrices:" << std::endl;
    productMatrix.printMat();

    Mat2D<double> transposedMatrix1 = matrix1.transpose();
    std::cout << "Transposed Matrix 1:" << std::endl;
    transposedMatrix1.printMat();

    Mat2D<double> transposedMatrix2 = matrix2.transpose();
    std::cout << "Transposed Matrix 2:" << std::endl;
    transposedMatrix2.printMat();

    int detMatrix1 = matrix1.determinant();
    std::cout << "Determinant of Matrix 1: " << matrix1.determinant() << std::endl;

    VecND<double> vec(2);
    vec[0] = 2;
    vec[1] = 3;
    std::cout << "Vector vec:" << std::endl;
    vec.printVec();

    Mat2D<double> matxvec = matrix1 * vec;

    std::cout << "Result of matrix1 * vector:" << std::endl;
    matxvec.printMat();
    std::cout << std::endl;
}

void test_all() {
    dynarray_test();
    queue_test();
    vecnd_test();
    //mat2d_test();
}
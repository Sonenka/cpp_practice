#include <iostream>
#include "tests.hpp"
#include "vecnd.hpp"
#include "mat2d.hpp"

void vecnd_test() {
    std::cout << "VECND_TEST" << std::endl;
    VecND vec1(4);
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 3;
    vec1[3] = 4;

   VecND vec2 = vec1;

    VecND vec3(4);
    vec3[0] = 10;
    vec3[1] = 20;
    vec3[2] = 30;
    vec3[3] = 40;

    VecND vecSum = vec1 + vec3;
    VecND vecMult = vec1 * vec3;

    std::cout << "Vector 1: ";
    vec1.printVec();

    std::cout << "Vector 2: ";
    vec2.printVec();

    std::cout << "Vector 3: ";
    vec3.printVec();

    std::cout << "Vector Sum: ";
    vecSum.printVec();

    std::cout << "Vector Sum: ";
    vecMult.printVec();
    std::cout << std::endl;
}

void mat2d_test() {
    std::cout << "MAT2D_TEST" << std::endl;
    Mat2D matrix1(2, 2);
    matrix1[0][0] = 1;
    matrix1[0][1] = 2;
    matrix1[1][0] = 3;
    matrix1[1][1] = 4;

    Mat2D matrix2(2, 2);
    matrix2[0][0] = 5;
    matrix2[0][1] = 6;
    matrix2[1][0] = 7;
    matrix2[1][1] = 8;

    std::cout << "Matrix 1:" << std::endl;
    matrix1.printMat();

    std::cout << "Matrix 2:" << std::endl;
    matrix2.printMat();

    Mat2D sumMatrix = matrix1 + matrix2;
    std::cout << "Sum of Matrices:" << std::endl;
    sumMatrix.printMat();

    Mat2D productMatrix = matrix1 * matrix2;
    std::cout << "Product of Matrices:" << std::endl;
    productMatrix.printMat();

    Mat2D transposedMatrix1 = matrix1.transpose();
    std::cout << "Transposed Matrix 1:" << std::endl;
    transposedMatrix1.printMat();

    Mat2D transposedMatrix2 = matrix2.transpose();
    std::cout << "Transposed Matrix 2:" << std::endl;
    transposedMatrix2.printMat();

    int detMatrix1 = matrix1.determinant();
    std::cout << "Determinant of Matrix 1: " << matrix1.determinant() << std::endl;

    VecND vec(2);
    vec[0] = 2;
    vec[1] = 3;
    std::cout << "Vector vec:" << std::endl;
    vec.printVec();

    Mat2D matxvec = matrix1 * vec;

    std::cout << "Result of matrix1 * vector:" << std::endl;
    matxvec.printMat();
}
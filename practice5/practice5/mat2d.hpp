#pragma once
#include "vecnd.hpp"

class Mat2D {
public:
    int rows, cols;
    std::vector<VecND> matrix;

    Mat2D();
    Mat2D(int rows_, int cols_);
    Mat2D(const Mat2D& other);

    VecND& operator[](int idx);
    const VecND& operator[](int idx) const;
    Mat2D operator+(const Mat2D other);
    Mat2D operator*(const Mat2D& other);
    Mat2D operator*(const VecND& other);
    Mat2D operator*(double other);

    void printMat();
    Mat2D transpose();
    Mat2D minor(int del_col);
    double determinant();
    Mat2D inverse();
    void printSolution();
    
};
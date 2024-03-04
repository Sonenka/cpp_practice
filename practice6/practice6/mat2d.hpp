#pragma once
#include "vecnd.hpp"

template <class T>
class Mat2D {
private:
    int rows, cols;
    std::vector<VecND<T>> matrix;

public:
    Mat2D();
    Mat2D(int rows_, int cols_);
    Mat2D(const Mat2D& other);

    VecND<T>& operator[](int idx);
    const VecND<T>& operator[](int idx) const;
    Mat2D operator+(const Mat2D other);
    Mat2D operator*(const Mat2D& other);
    Mat2D operator*(const VecND<T>& other);
    Mat2D operator*(T other);

    void printMat();
    Mat2D transpose();
    Mat2D minor(int del_col);
    double determinant();
    Mat2D inverse();
    void printSolution();

};
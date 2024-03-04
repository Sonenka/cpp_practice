#include "mat2d.hpp"
#include <cmath>

template <class T>
Mat2D<T>::Mat2D() : rows(0), cols(0) {}

template <class T>
Mat2D<T>::Mat2D(int rows_, int cols_) : rows(rows_), cols(cols_), matrix(rows, VecND<T>(cols)) {}

template <class T>
Mat2D<T>::Mat2D(const Mat2D<T>& other) : rows(other.rows), cols(other.cols), matrix(other.matrix) {}

template <class T>
VecND<T>& Mat2D<T>::operator[](int idx) {
	return matrix[idx];
}

template <class T>
const VecND<T>& Mat2D<T>::operator[](int idx) const {
	return matrix[idx];
}

template <class T>
Mat2D<T> Mat2D<T>::operator+(const Mat2D<T> other) {
	if (rows != other.rows || cols != other.cols) {
		std::cout << "Wrong matrix sizes." << std::endl;
		return Mat2D(0, 0);
	}

	Mat2D result(rows, cols);

	for (size_t i = 0; i < rows; i++) {
		result[i] = matrix[i] + other[i];
	}

	return result;
}

template <class T>
Mat2D<T> Mat2D<T>::operator*(const Mat2D<T>& other) {
	if (cols != other.rows) {
		std::cout << "Wrong matrix sizes." << std::endl;
		return Mat2D(0, 0);
	}

	Mat2D result(rows, other.cols);

	for (size_t i = 0; i < rows; i++) {
		for (int j = 0; j < other.cols; j++) {
			for (int k = 0; k < cols; k++) {
				result[i][j] += (matrix[i][k] * other[k][j]);
			}
		}
	}

	return result;
}

template <class T>
Mat2D<T> Mat2D<T>::operator*(const VecND<T>& other) {
	if (cols != other.size()) {
		std::cout << "Wrong matrix and vector sizes." << std::endl;
		return Mat2D(0, 0);
	}

	Mat2D result(rows, 1);

	for (size_t i = 0; i < rows; i++) {
		result[i][0] = 0;
		for (int k = 0; k < cols; k++) {
			result[i][0] += matrix[i][k] * other[k];
		}
	}

	return result;
}

template <class T>
Mat2D<T> Mat2D<T>::operator*(T other) {
	Mat2D result(rows, cols);

	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			result[i][j] = matrix[i][j] * other;
		}
	}

	return result;
}

template <class T>
void Mat2D<T>::printMat() {
	for (size_t i = 0; i < rows; i++) {
		matrix[i].printVec();
	}
}

template <class T>
Mat2D<T> Mat2D<T>::transpose() {
	Mat2D result(cols, rows);

	for (size_t i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			result[j][i] = matrix[i][j];
		}
	}

	return result;
}

template <class T>
Mat2D<T> Mat2D<T>::minor(int del_col) {
	Mat2D result(rows - 1, cols - 1);
	int c = 0;

	for (int i = 0; i < rows; i++) {
		if (i == 0) {
			continue;
		}

		for (int j = 0; j < cols; j++) {
			if (j == del_col) {
				continue;
			}
			result[c / result.cols][c % result.cols] = matrix[i][j];
			c++;
		}
	}

	return result;
}

template <class T>
double Mat2D<T>::determinant() {
	if (cols != rows) {
		std::cout << "Wrong matrix size." << std::endl;
		return 0;
	}

	if (rows == 1) {
		return matrix[0][0];
	}

	if (rows == 2) {
		return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	}

	int result = 0;

	for (int i = 0; i < rows; i++) {
		Mat2D minor = this->minor(i);
		result += matrix[0][i] * std::pow(-1, 2 + i) * minor.determinant();
	}

	return result;
}

template <class T>
Mat2D<T> Mat2D<T>::inverse() {
	Mat2D result(rows, cols);

	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			result[i][j] = matrix[i][j];
		}
	}

	double determinant = result.determinant();
	result = result.transpose();

	return result * (1 / determinant);
}

template <class T>
void Mat2D<T>::printSolution() {
	std::cout << "Solution x:" << std::endl;
	for (size_t i = 0; i < rows; i++) {
		std::cout << "x" << i << " = " << matrix[i][0] << std::endl;
	}
}

template Mat2D<double> ::Mat2D(int rows_, int cols_);
template Mat2D<double>::Mat2D(const Mat2D<double>& other);
template const VecND<double>& Mat2D<double>::operator[](int idx) const;
template Mat2D<double> Mat2D<double>::operator+(const Mat2D<double> other);
template Mat2D<double> Mat2D<double>::operator*(const Mat2D<double>& other);
template Mat2D<double> Mat2D<double>::operator*(const VecND<double>& other);
template void Mat2D<double>::printMat();
template Mat2D<double> Mat2D<double>::transpose();
template double Mat2D<double>::determinant();
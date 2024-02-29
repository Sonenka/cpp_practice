#include "mat2d.hpp"
#include <cmath>

Mat2D::Mat2D() : rows(0), cols(0) {}

Mat2D::Mat2D(int rows_, int cols_) : rows(rows_), cols(cols_), matrix(rows, VecND(cols)) {}

Mat2D::Mat2D(const Mat2D& other) : rows(other.rows), cols(other.cols), matrix(other.matrix) {}

VecND& Mat2D::operator[](int idx) {
	return matrix[idx];
}

const VecND& Mat2D::operator[](int idx) const {
	return matrix[idx];
}

Mat2D Mat2D::operator+(const Mat2D other) {
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

Mat2D Mat2D::operator*(const Mat2D& other) {
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

Mat2D Mat2D::operator*(const VecND& other) {
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

void Mat2D::printMat() {
	for (size_t i = 0; i < rows; i++) {
		matrix[i].printVec();
	}
}

Mat2D Mat2D::transpose() {
	Mat2D result(cols, rows);

	for (size_t i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			result[j][i] = matrix[i][j];
		}
	}

	return result;
}

Mat2D Mat2D::minor(int del_col) {
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

int Mat2D::determinant() {
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




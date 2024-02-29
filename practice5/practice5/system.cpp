#include "system.hpp"

System::System(const Mat2D A_, const VecND b_) : A(A_), b(b_) {}

Mat2D System::solve() {
	int determinant = A.determinant();

	if (determinant == 0) {
		std::cout << "Determinant = 0 -> no solutions." << std::endl;
		return Mat2D(0, 0);
	}

	Mat2D inversed = A.inverse();

	Mat2D result = inversed * b;
	return result;
}

void System::printSystem() {
	std::cout << "Linear System of Equations:" << std::endl;

	for (size_t i = 0; i < A.rows; i++) {
		for (size_t j = 0; j < A.cols; j++) {
			if (j != 0) std::cout << " + ";
			std::cout << A[i][j] << "x" << j;
		}
		std::cout << " = " << b[i] << std::endl;
	}
}
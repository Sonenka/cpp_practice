#pragma once
#include <iostream>
#include "mat2d.hpp"
#include "vecnd.hpp"

class System {
public:
	Mat2D A;
	VecND b;

	System(const Mat2D A_, const VecND b_);

	Mat2D solve();
	void printSystem();
};
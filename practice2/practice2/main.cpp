#include <iostream>
#include <cctype>

#include "sorting.hpp"


int main() {
	int t, n;
	std::cout << "Choose data type:\n" << "1. Int\n" << "2. Short\n" << "3. Double\n" << "4. Char\n";
	std::cin >> t;

	if ((t <= 0) || (t > 4)) {
		std::cout << "Wrong data type\n";
		return 0;
	}

	std::cout << "Enter n\n";
	std::cin >> n;

	std::cout << "Enter " << n << " numbers or chars\n";

	//int
	if (t == 1) {
		int* a = new int[n];
		for (int i = 0; i < n; i++) std::cin >> a[i];
		sorting(a, n);
		for (int i = 0; i < n; i++) std::cout << a[i] << " ";
		delete[] a;
	}

	//short
	else if (t == 2) {
		short* a = new short[n];
		for (int i = 0; i < n; i++) std::cin >> a[i];
		sorting(a, n);
		for (int i = 0; i < n; i++) std::cout << a[i] << " ";
		delete[] a;
	}

	//double
	else if (t == 3) {
		double* a = new double[n];
		for (int i = 0; i < n; i++) std::cin >> a[i];
		sorting(a, n);
		for (int i = 0; i < n; i++) std::cout << a[i] << " ";
		delete[] a;
	}
	
	//char
	else if (t == 4) {
		char* a = new char[n];
		for (int i = 0; i < n; i++) std::cin >> a[i];
		sorting(a, n);
		for (int i = 0; i < n; i++) std::cout << a[i] << " ";
		delete[] a;
	}

	return 0;
}
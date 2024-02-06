#include <iostream>
#include <cctype>
#include <algorithm>
using namespace std;

#define TASK_3

#ifdef TASK_1
int main() {
	int n;
	bool flag = 0;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	while (flag == 0) {
		flag = 1;
		for (int i = 0; i < n - 1; i++) {
			if (a[i] > a[i + 1]) {
				int tmp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = tmp;
				flag = 0;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	
	delete[] a;
	return 0;
}
#endif

#ifdef TASK_2
void sorting(int a[], int n) {
	bool flag = 0;
	while (flag == 0) {
		flag = 1;
		for (int i = 0; i < n - 1; i++) {
			if (a[i] > a[i + 1]) {
				int tmp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = tmp;
				flag = 0;
			}
		}
	}
}

void sorting(short a[], int n) {
	bool flag = 0;
	while (flag == 0) {
		flag = 1;
		for (int i = 0; i < n - 1; i++) {
			if (a[i] > a[i + 1]) {
				int tmp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = tmp;
				flag = 0;
			}
		}
	}
}

void sorting(double a[], int n) {
	bool flag = 0;
	while (flag == 0) {
		flag = 1;
		for (int i = 0; i < n - 1; i++) {
			if (a[i] > a[i + 1]) {
				int tmp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = tmp;
				flag = 0;
			}
		}
	}
}

int main() {
	int t, n;
	cout << "Choose data type:\n" << "1. Int\n" << "2. Short\n" << "3. Double\n";
	cin >> t;
	cout << "Enter n\n";
	cin >> n;

	//int
	if (t == 1) {
		int* a = new int[n];
		for (int i = 0; i < n; i++) cin >> a[i];
		sorting(a, n);
		for (int i = 0; i < n; i++) cout << a[i] << " ";
		delete[] a;
	}

	//short
	else if (t == 2) {
		short* a = new short[n];
		for (int i = 0; i < n; i++) cin >> a[i];
		sorting(a, n);
		for (int i = 0; i < n; i++) cout << a[i] << " ";
		delete[] a;
	}

	//double
	else if (t == 3) {
		double* a = new double[n];
		for (int i = 0; i < n; i++) cin >> a[i];
		sorting(a, n);
		for (int i = 0; i < n; i++) cout << a[i] << " ";
		delete[] a;
	}

	else {
		cout << "Wrong data type\n";
		return 0;
	}

	return 0;
}
#endif

#ifdef TASK_3
template <typename T>
void sorting(T a[], int n) {
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n - i- 1; ++j) {
			if (a[j] > a[j + 1]) {
				T tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}

template <>
void sorting<char>(char a[], int n) {
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			if (isalpha(a[j]) && isalpha(a[j + 1])) {
				if (tolower(a[j]) > tolower(a[j + 1])) {
					char tmp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = tmp;
				}
			}

			else if (isalpha(a[j])) {
				a[j + 1] = ' ';
			}

			else if (isalpha(a[j + 1])) {
				char tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;

				a[j + 1] = ' ';
			}

			else {
				a[j] = ' ';
				a[j + 1] = ' ';
			}
		}
	}
}

int main() {
	int t, n;
	cout << "Choose data type:\n" << "1. Int\n" << "2. Short\n" << "3. Double\n" << "4. Char\n";
	cin >> t;

	if ((t <= 0) || (t > 4)) {
		cout << "Wrong data type\n";
		return 0;
	}

	cout << "Enter n\n";
	cin >> n;


	//int
	if (t == 1) {
		cout << "Enter " << n << " ints\n";
		int* a = new int[n];
		for (int i = 0; i < n; i++) cin >> a[i];
		sorting(a, n);
		for (int i = 0; i < n; i++) cout << a[i] << " ";
		delete[] a;
	}

	//short
	else if (t == 2) {
		cout << "Enter " << n << " shorts\n";
		short* a = new short[n];
		for (int i = 0; i < n; i++) cin >> a[i];
		sorting(a, n);
		for (int i = 0; i < n; i++) cout << a[i] << " ";
		delete[] a;
	}

	//double
	else if (t == 3) {
		cout << "Enter " << n << " doubles\n";
		double* a = new double[n];
		for (int i = 0; i < n; i++) cin >> a[i];
		sorting(a, n);
		for (int i = 0; i < n; i++) cout << a[i] << " ";
		delete[] a;
	}
	
	//char
	else if (t == 4) {
		cout << "Enter " << n << " chars\n";
		char* a = new char[n];
		for (int i = 0; i < n; i++) cin >> a[i];
		sorting(a, n);
		for (int i = 0; i < n; i++) cout << a[i] << " ";
		delete[] a;
	}

	return 0;
}
#endif
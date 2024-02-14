#ifndef SORTING_HPP
#define SORTING_HPP
#include <cctype>
#include "sorting.hpp"

template <typename T>
void sorting(T a[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (a[j] > a[j + 1]) {
                T tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

template <>
void sorting(char a[], int n) {
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



#endif
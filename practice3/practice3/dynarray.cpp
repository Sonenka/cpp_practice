#include "dynarray.hpp"
#include <iostream>

DynArray::DynArray() {
    data_size = 0;
    capacity = 1;
    data = new double[capacity];
}

DynArray::DynArray(int cap) {
    data_size = 0;
    capacity = cap;
    data = new double[cap];
}

DynArray::DynArray(const DynArray& other) {
    data_size = other.data_size;
    capacity = other.capacity;
    data = new double[capacity];
    for (int i = 0; i < data_size; i++) {
        data[i] = other.data[i];
    }
}

DynArray::~DynArray() {
    std::cout << "No mem leaks\n";
    delete[] data;
}

void DynArray::resize() {
    capacity *= 2;
    double* new_data = new double[capacity];
    for (int i = 0; i < data_size; i++) {
        new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;
}

void DynArray::append(double value) {
    if (data_size == capacity) {
        resize();
    }
    data[data_size++] = value;
}

int DynArray::size() {
    return data_size;
}

double DynArray::get(int index) {
    return data[index];
}
#include "dynarray.hpp"
#include <iostream>

DynArray::DynArray() {
    data_size = 0;
    capacity = 1;
    data = new double[capacity];
    ++obj_alive;
}

DynArray::DynArray(int capacity_) {
    data_size = 0;
    capacity = capacity_;
    data = new double[capacity_];
    ++obj_alive;
}

DynArray::DynArray(const DynArray& other) {
    data_size = other.data_size;
    capacity = other.capacity;
    data = new double[capacity];
    for (int i = 0; i < data_size; i++) {
        data[i] = other.data[i];
    }
    ++obj_alive;
}

DynArray::~DynArray() {
    //cout << "No mem leaks\n";
    delete[] data;
    --obj_alive;
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

void DynArray::printArray() {
    for (int i = 0; i < data_size; i++) {
        std::cout << data[i] << ' ';
    }
    std::cout << std::endl;
}

DynArray& DynArray::operator=(const DynArray& rhs) {
    if (this == &rhs) {
        return *this;
    }

    delete[] data;
    data_size = rhs.data_size;
    capacity = rhs.capacity;
    data = new double[capacity];

    for (int i = 0; i < rhs.data_size; i++) data[i] = rhs.data[i];
    return *this;
}

double& DynArray::operator[](int id) {
    if (id < 0 || id > data_size) {
        throw std::out_of_range("Out of range\n");
    }

    return data[id];
}

DynArray DynArray::operator+(const DynArray rhs) {
    DynArray united(data_size + rhs.data_size);


    for (int i = 0; i < data_size; i++) {
        united.append(data[i]);
    }

    for (int i = data_size; i < data_size + rhs.data_size; i++) {
        united.append(rhs.data[i - data_size]);
    }

    return united;
}

DynArray DynArray::operator<<(int x) {
    for (int j = 0; j < x; j++) {
        double tmp = data[0];
        for (int i = 0; i < data_size - 1; i++) {
            data[i] = data[i + 1];
        }
        data[data_size - 1] = tmp;
    }
    return *this;
}

DynArray DynArray::operator>>(int x) {
    for (int j = 0; j < x; j++) {
        double tmp = data[data_size - 1];
        for (int i = data_size - 1; i > 0; i--) {
            data[i] = data[i - 1];
        }
        data[0] = tmp;
    }
    return *this;
}
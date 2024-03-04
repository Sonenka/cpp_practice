#include "dynarray.hpp"
#include <iostream>
#include <vector>

template<class T>
int DynArray<T>::obj_alive = 0;

template<class T>
DynArray<T>::DynArray() : size(0) {
    obj_alive++;
}

template<class T>
DynArray<T>::DynArray(int size) : size(0) {
    data.reserve(size);
    obj_alive++;
}

template<class T>
DynArray<T>::DynArray(const DynArray& other) : size(other.size), data(other.data) {
    obj_alive++;
}

template<class T>
DynArray<T>::~DynArray() {
    obj_alive--;
}

template<class T>
void DynArray<T>::append(T value) {
    data.push_back(value);
    size++;
}

template<class T>
int DynArray<T>::getSize() {
    return size;
}

template<class T>
double DynArray<T>::get(int index) {
    return data[index];
}

template<class T>
void DynArray<T>::printArray() {
    for (int i = 0; i < size; i++) {
        std::cout << data[i] << ' ';
    }
    std::cout << std::endl;
}

template<class T>
DynArray<T>& DynArray<T>::operator=(const DynArray<T>& other) {
    if (this == &other) {
        return *this;
    }

    size = other.size;
    data = other.data;

    return *this;
}

template<class T>
DynArray<T> DynArray<T>::operator+(const DynArray& other) {
    DynArray ans(this->size + other.size);
    for (int i = 0; i < this->size; i++) ans.append(this->data[i]);
    for (int i = 0; i < other.size; i++) ans.append(other.data[i]);
    return ans;
}


template<class T>
T& DynArray<T>::operator[](int id) {
    if (id < 0 || id > size) {
        throw std::out_of_range("Out of range\n");
    }

    return data[id];
}

template<class T>
DynArray<T>& DynArray<T>::operator>>(int shift) {
    if (shift < 0) {
        shift = this->size - ((-shift) % this->size);
    }
    else {
        shift = shift % this->size;
    }

    if (shift == 0) {
        return *this;
    }

    DynArray<T> temp(*this);

    for (int i = 0; i < this->size; ++i) {
        int new_pos = (i + shift) % this->size;
        this->data[new_pos] = temp.data[i];
    }

    return *this;
}

template<class T>
DynArray<T>& DynArray<T>::operator<<(int shift) {
    if (shift < 0) {
        shift = this->size - ((-shift) % this->size);
    }
    else {
        shift = shift % this->size;
    }

    if (shift == 0) {
        return *this;
    }

    DynArray<T> temp(*this);
    for (int i = 0; i < this->size; ++i) {
        int new_pos = (i - shift + this->size) % this->size;
        this->data[new_pos] = temp.data[i];
    }

    return *this;
}

template DynArray<double>::DynArray();
template DynArray<double>::DynArray(int capacity_);
template void DynArray<double>::append(double value);
template int DynArray<double>::getSize();
template double DynArray<double>::get(int index);
template void DynArray<double>::printArray();
template DynArray<double>::DynArray(const DynArray<double>& other);
template DynArray<double>& DynArray<double>::operator=(const DynArray<double>& other);
template DynArray<double> DynArray <double>::operator+(const DynArray& other);
template double& DynArray<double>::operator[](int id);
template DynArray<double>& DynArray<double>::operator<<(int x);
template DynArray<double>& DynArray<double>::operator>>(int x);
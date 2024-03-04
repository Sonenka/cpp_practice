#include "vecnd.hpp"

template<class T>
VecND<T>::VecND() : vector(0) {}

template<class T>
VecND<T>::VecND(int n) : vector(n) {}

template<class T>
VecND<T>::VecND(const VecND<T>& other) : vector(other.vector) {}

template<class T>
T& VecND<T>::operator[](int id) {
    if (id < 0 || id >= vector.size()) {
        throw std::out_of_range("Out of range\n");
    }

    return vector[id];
}

template<class T>
const T& VecND<T>::operator[](int id) const {
    if (id < 0 || id >= vector.size()) {
        throw std::out_of_range("Out of range\n");
    }

    return vector[id];
}

template<class T>
VecND<T>& VecND<T>::operator=(const VecND<T>& other) {
    if (this == &other) {
        return *this;
    }

    vector = other.vector;

    return *this;
}

template<class T>
VecND<T> VecND<T>::operator+(const VecND& other) {
    if (this->size() != other.size()) {
        std::cout << "Wrong size of vectors.\n";
        return VecND<T>(0);
    }

    VecND res(this->size());

    for (int i = 0; i < this->size(); i++) {
        res[i] = (*this)[i] + other[i];
    }

    return res;
}

template<class T>
VecND<T> VecND<T>::operator*(const VecND<T>& other) {
    if (this->size() != other.size()) {
        std::cout << "Wrong size of vectors.\n";
        return VecND<T>(0);
    }

    VecND<T> res(this->size());

    for (int i = 0; i < this->size(); i++) {
        res[i] = (*this)[i] * other[i];
    }

    return res;
}

template<class T>
int VecND<T>::size() const {
    return vector.size();
}

template<class T>
void VecND<T>::printVec() {
    for (int i = 0; i < size(); i++) {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;
}

template VecND<double>::VecND(int n);
template VecND<double>::VecND(const VecND<double>& other);
template const double& VecND<double>::operator[](int id) const;
template double& VecND<double>::operator[](int id);
template VecND<double> VecND<double>::operator+(const VecND& other);
template VecND<double> VecND<double>::operator*(const VecND<double>& other);
template void VecND<double>::printVec();
template VecND<double>& VecND<double>::operator=(const VecND<double>& other);
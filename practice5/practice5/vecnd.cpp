#include "vecnd.hpp"

VecND::VecND() : vector(0) {}

VecND::VecND(int n) : vector(n) {}

VecND::VecND(const VecND& other) : vector(other.vector) {}

double& VecND::operator[](int id) {
    if (id < 0 || id >= vector.size()) {
        throw std::out_of_range("Out of range\n");
    }

    return vector[id];
}

const double& VecND::operator[](int id) const {
    if (id < 0 || id >= vector.size()) {
        throw std::out_of_range("Out of range\n");
    }

    return vector[id];
}

VecND& VecND::operator=(const VecND& other) {
    if (this == &other) {
        return *this;
    }

    vector = other.vector;

    return *this;
}

VecND VecND::operator+(const VecND& other) {
    if (this->size() != other.size()) { 
        std::cout << "Wrong size of vectors.\n";
        return VecND(0);
    }

    VecND res(this->size());

    for (int i = 0; i < this->size(); i++) {
        res[i] = (*this)[i] + other[i]; 
    }

    return res;
}

VecND VecND::operator*(const VecND& other) {
    if (this->size() != other.size()) { 
        std::cout << "Wrong size of vectors.\n";
        return VecND(0);
    }

    VecND res(this->size());

    for (int i = 0; i < this->size(); i++) {
        res[i] = (*this)[i] * other[i]; 
    }

    return res;
}

int VecND::size() const {
    return vector.size();
}

void VecND::printVec() {
    for (int i = 0; i < size(); i++) {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;
}
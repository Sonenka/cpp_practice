#pragma once

#include <iostream> 
#include <vector>

template <class T>
class VecND {
private:
    std::vector<double> vector;

public:
    VecND();
    VecND(int n_);
    VecND(const VecND& other);

    T& operator[](int id);
    const T& operator[](int id) const;
    VecND& operator=(const VecND& other);
    VecND operator+(const VecND& other);
    VecND operator*(const VecND& other);

    int size() const;
    void printVec();
};


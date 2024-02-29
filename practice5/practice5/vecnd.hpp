#pragma once

#include <iostream> 
#include <vector>

class VecND {
public:
    std::vector<double> vector;

    VecND();
    VecND(int n_);
    VecND(const VecND& other);
    
    double& operator[](int id);
    const double& operator[](int id) const;
    VecND& operator=(const VecND& other);
    VecND operator+(const VecND& other);
    VecND operator*(const VecND& other);

    int size() const;
    void printVec();
};


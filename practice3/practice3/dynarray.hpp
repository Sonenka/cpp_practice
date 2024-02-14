#ifndef DYNARRAY_HPP
#define DYNARRAY_HPP
#include <iostream>

class DynArray {
public:
    double* data;
    int data_size;
    int capacity;

    //constructors
    DynArray();

    DynArray(int cap);

    DynArray(const DynArray& other);

    //destructor
    ~DynArray();

    //methods
    void resize();

    void append(double value);

    int size();

    double get(int index);
};
#endif
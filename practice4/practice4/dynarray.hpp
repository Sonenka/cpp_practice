#ifndef DYNARRAY_HPP
#define DYNARRAY_HPP
#include <iostream>

class DynArray {
public:
    double* data;
    int data_size;
    int capacity;

    static long obj_alive;
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

    void printArray();

    //operators
    DynArray& operator=(const DynArray& rhs);

    double& operator[](int id);

    DynArray operator+(const DynArray rhs);

    DynArray operator<<(int x);

    DynArray operator>>(int x);
};



#endif
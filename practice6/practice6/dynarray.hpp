#pragma once
#include <iostream>
#include <vector>

template<class T>
class DynArray {
private:
    int size;
    std::vector<T> data;
public:
    static int obj_alive;

    DynArray();
    DynArray(int cap);
    DynArray(const DynArray& other);
    ~DynArray();

    void append(T value);
    double get(int index);
    void printArray();
    int getSize();

    DynArray& operator=(const DynArray& other);
    DynArray operator+(const DynArray& other);
    T& operator[](int id);
    DynArray& operator<<(int shift);
    DynArray& operator>>(int shift);
};




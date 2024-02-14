#include "mystack.hpp"
#include <iostream>

MyStack::MyStack() {
    size = 0;
    capacity = 1;
    data = new int[capacity];
}

MyStack::MyStack(const MyStack& other) {
    size = other.size;
    capacity = other.capacity;
    data = new int[capacity];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

MyStack::~MyStack() {
    std::cout << "No mem leaks\n";
    delete[] data;
}

void MyStack::resize() {
    capacity *= 2;
    int* new_data = new int[capacity];
    for (int i = 0; i < size; i++) {
        new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;
}

void MyStack::push(int value) {
    if (size == capacity) {
        resize();
    }
    data[size++] = value;
}

int MyStack::pop() {
    if (size == 0) {
        std::cout << "The stack is empty\n";
        return -1;
    }
    return data[--size];
}

int MyStack::top() {
    return data[size - 1];
}

bool MyStack::isEmpty() {
    return (size == 0);
}

int MyStack::getSize() {
    return size;
}
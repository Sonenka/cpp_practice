#include <iostream>
using namespace std;

class DynArray {
private:
    double* data;
    int data_size;
    int capacity;

    void resize() {
        capacity *= 2;
        double* new_data = new double[capacity];
        for (int i = 0; i < data_size; i++) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
    }
public:
    //constructors
    DynArray() {
        data_size = 0;
        capacity = 1;
        data = new double[capacity];
    }

    DynArray(int cap) {
        data_size = 0;
        capacity = cap;
        data = new double[cap];
    }

    //destructor
    ~DynArray() {
        cout << "No mem leaks\n";
        delete[] data;
    }

    //methods
    void append(double value) {
        if (data_size == capacity) {
            resize();
        }
        data[data_size++] = value;
    }

    int size() {
        return data_size;
    }

    double get(int index) {
        return data[index];
    }
};

class MyStack {
private:
    int size;
    int capacity;
    int* data;

    void resize() {
        capacity *= 2;
        int* new_data = new int[capacity];
        for (int i = 0; i < size; i++) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
    }

public:
    //constructor
    MyStack() {
        size = 0;
        capacity = 1;
        data = new int[capacity];
    }

    //destructor
    ~MyStack() {
        cout << "No mem leaks\n";
        delete[] data;
    }

    //methods
    void push(int value) {
        if (size == capacity) {
            resize();
        }
        data[size++] = value;
    }

    int pop() {
        if (size == 0) {
            cout << "The stack is empty\n";
            return -1;
        }
        return data[--size];
    }

    int top() {
        return data[size - 1];
    }

    bool isEmpty() {
        return (size == 0);
    }

    int getSize() {
        return size;
    }
};

void DynArrayExample() {
    cout << "Working with DynArray:\n";
    DynArray arr(10); // reserve memory for 10 array members
    arr.append(1.0);

    for (size_t i = 0; i < 15; i++) // make sure that the array can dynamically resize
    {
        arr.append(i + 0.0);
    }

    for (size_t j = 0; j < arr.size(); j++)
    {
        cout << arr.get(j) << ' '; // should output all 16 elements
    }
    cout << endl;
}

void MyStackExample() {
    cout << "\nWorking with MyStack:\n";

    MyStack stack;

    stack.push(5);
    stack.push(10);
    stack.push(15);

    cout << "Top element: " << stack.top() << "\n"; // Output: 15

    cout << "Popped element: " << stack.pop() << "\n"; // Output: 15
    cout << "Stack size: " << stack.getSize() << "\n"; // Output: 2

    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << "\n"; // Output: No
}

int main(int argc, char* argv[])
{
    DynArrayExample();
    
    MyStackExample();

    return 0;
}
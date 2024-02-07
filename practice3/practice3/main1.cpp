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

int main(int argc, char* argv[])
{
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
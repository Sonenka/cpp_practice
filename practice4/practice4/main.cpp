#include <iostream>
using namespace std;

class Vec3D {
public:
	double x, y, z;
	Vec3D() : x(0.0), y(0.0), z(0.0) {}
	Vec3D(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {}
	
	double operator*(const Vec3D& v2) {
		return x * v2.x + y * v2.y + z * v2.z;
	}

	Vec3D operator& (const Vec3D v2) {
		return Vec3D(y * v2.z - z * v2.y, z * v2.x - x * v2.z, x * v2.y - y * v2.x);
	}
};

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
    static long obj_alive;
    //constructors
    DynArray() {
        data_size = 0;
        capacity = 1;
        data = new double[capacity];
        ++obj_alive;
    }

    DynArray(int cap) {
        data_size = 0;
        capacity = cap;
        data = new double[cap];
        ++obj_alive;
    }

    DynArray(const DynArray& other) {
        data_size = other.data_size;
        capacity = other.capacity;
        data = new double[capacity];
        for (int i = 0; i < data_size; i++) {
            data[i] = other.data[i];
        }
        ++obj_alive;
    }

    //destructor
    ~DynArray() {
        //cout << "No mem leaks\n";
        delete[] data;
        --obj_alive;
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

    void printArray() {
        for (int i = 0; i < data_size; i++) {
            cout << data[i] << ' ';
        }
        cout << endl;
    }

    //operators
    DynArray& operator=(const DynArray& rhs) {
        if (this == &rhs) {
            return *this;
        }

        delete[] data;
        data_size = rhs.data_size;
        capacity = rhs.capacity;
        data = new double[capacity];

        for (int i = 0; i < rhs.data_size; i++) data[i] = rhs.data[i];
        return *this;
    }

    double& operator[](int id) {
        if (id < 0 || id > data_size) {
            throw out_of_range("Out of range\n");
        }

        return data[id];
    }

    DynArray operator+(const DynArray rhs) {
        DynArray united(data_size + rhs.data_size);
        

        for (int i = 0; i < data_size; i++) {
            united.append(data[i]);
        }
        
        for (int i = data_size; i < data_size + rhs.data_size; i++) {
            united.append(rhs.data[i - data_size]);
        }

        return united;
    }

    DynArray operator<<(int x) {
       for (int j = 0; j < x; j++) {
            double tmp = data[0];
            for (int i = 0; i < data_size - 1; i++) {
                data[i] = data[i + 1];
            }
            data[data_size-1] = tmp;
        }
       return *this;
    }

    DynArray operator>>(int x) {
        for (int j = 0; j < x; j++) {
            double tmp = data[data_size-1];
            for (int i = data_size - 1; i > 0; i--) {
                data[i] = data[i - 1];
            }
            data[0] = tmp;
        }
        return *this;
    }
};

long DynArray::obj_alive = 0;

void example_vec3d() {
    cout << "Working with vec3d\n";
    Vec3D vec1(1, 1.5, 2), vec2(0.5, 4, 2);
    double dot_prod = vec1 * vec2;
    cout << dot_prod << "\n";

    Vec3D cross_prod = vec1 & vec2;
    cout << cross_prod.x << ' ' << cross_prod.y << ' ' << cross_prod.z << "\n";
}

void example_dynarray() {
    cout << endl;
    cout << "Working with DynArray\n";
    DynArray arr1;
    arr1.append(1.0);
    arr1.append(2.0);
    arr1.append(3.0);

    DynArray arr2(3);
    arr2.append(4.0);
    arr2.append(5.0);
    arr2.append(6.0);

    arr1 << 2;
    arr2 >> 1;

    DynArray arr3 = arr1 + arr2;

    cout << "Array 1 elements:" << "\n";
    for (int i = 0; i < arr1.size(); i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    cout << "Array 2 elements:" << "\n";
    for (int i = 0; i < arr2.size(); i++) {
        cout << arr2.get(i) << " ";
    }
    cout << endl;

    cout << "Array 3 elements (after concatenation):" << "\n";
    arr3.printArray();

    DynArray arr4;
    arr4 = arr3 << 1;
    arr4[0] = 100;
    cout << "Array 4 elements:" << "\n";
    arr4.printArray();

    cout << "Number of DynArray objects alive: " << DynArray::obj_alive << endl;

}

int main() {
    example_vec3d();
    example_dynarray();

    
    return 0;
}

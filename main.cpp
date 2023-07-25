#include <iostream>

template<typename T>
class Matrix {
private:
    T** data;
    int rows;
    int cols;

public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {

        data = new T * [rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new T[cols];
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = 0;
            }
        }
    }

    virtual ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }
};

template<typename A>
class Array {
    A* ptr;
    int size;
public:
    Array(int size) : size(size) { 
        ptr = new A[size];
    }
    virtual ~Array() { 
        delete[] ptr;
    }
};

int main() {
    Matrix<int> i_Matrix(3, 3);
    Matrix<double> d_Matrix(2, 2);
    Array<int> i_Array(5);
    Array<float> f_Array(3.7f);
    return 0;
}

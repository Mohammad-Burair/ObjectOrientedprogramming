/* 
name: mohammad burair
roll number: 24k 0775
section: bcs-1c
date: 11-05-2025
description: matrix class with dimension mismatch exception handling
*/

#include <iostream>
#include <stdexcept>
#include <sstream>

using namespace std;

class dimensionmismatchexception : public exception {
private:
    string message;
public:
    dimensionmismatchexception(int rows1, int cols1, int rows2, int cols2) {
        stringstream ss;
        ss << "dimensionmismatchexception - matrices must have same dimensions ("
           << rows1 << "x" << cols1 << " vs " << rows2 << "x" << cols2 << ")!";
        message = ss.str();
    }
    
    const char* what() const noexcept override {
        return message.c_str();
    }
};

template <typename t>
class matrix {
private:
    t** data = nullptr;
    int rows;
    int cols;
    
    void allocatememory() {
        data = new t*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new t[cols];
        }
    }
    
    void deallocatememory() {
        if (data) {
            for (int i = 0; i < rows; ++i) {
                delete[] data[i];
            }
            delete[] data;
            data = nullptr;
        }
    }
    
public:
    matrix(int rows, int cols) : rows(rows), cols(cols) {
        allocatememory();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = t();
            }
        }
    }
    
    matrix(const matrix& other) : rows(other.rows), cols(other.cols) {
        allocatememory();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }
    
    ~matrix() {
        deallocatememory();
    }
    
    matrix& operator=(const matrix& other) {
        if (this != &other) {
            deallocatememory();
            rows = other.rows;
            cols = other.cols;
            allocatememory();
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    data[i][j] = other.data[i][j];
                }
            }
        }
        return *this;
    }
    
    int getrows() const { return rows; }
    int getcols() const { return cols; }
    
    t& operator()(int row, int col) {
        return data[row][col];
    }
    
    const t& operator()(int row, int col) const {
        return data[row][col];
    }
    
    matrix operator+(const matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw dimensionmismatchexception(rows, cols, other.rows, other.cols);
        }
        
        matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
    
    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    try {
        matrix<int> a(2, 2);
        matrix<int> b(2, 2);
        
        a(0, 0) = 1; a(0, 1) = 2;
        a(1, 0) = 3; a(1, 1) = 4;
        
        b(0, 0) = 5; b(0, 1) = 6;
        b(1, 0) = 7; b(1, 1) = 8;
        
        cout << "matrix a:" << endl;
        a.print();
        cout << "\nmatrix b:" << endl;
        b.print();
        
        matrix<int> c = a + b;
        cout << "\na + b:" << endl;
        c.print();
        
        matrix<int> d(3, 3);
        cout << "\nattempting to add 2x2 and 3x3 matrices..." << endl;
        matrix<int> e = a + d;
    }
    catch (const dimensionmismatchexception& e) {
        cerr << "error: " << e.what() << endl;
    }
    catch (const exception& e) {
        cerr << "standard exception: " << e.what() << endl;
    }
    
    return 0;
}

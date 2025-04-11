#include <iostream>
using namespace std;

class matrix2x2 {
private:
    int a, b, c, d;

public:
    matrix2x2(int w=0, int x=0, int y=0, int z=0) : a(w), b(x), c(y), d(z) {}

    matrix2x2 operator+(const matrix2x2& other) {
        return matrix2x2(a + other.a, b + other.b, c + other.c, d + other.d);
    }

    matrix2x2 operator-(const matrix2x2& other) {
        return matrix2x2(a - other.a, b - other.b, c - other.c, d - other.d);
    }

    matrix2x2 operator*(const matrix2x2& other) {
        return matrix2x2(
            a*other.a + b*other.c,
            a*other.b + b*other.d,
            c*other.a + d*other.c,
            c*other.b + d*other.d
        );
    }

    friend int determinant(const matrix2x2& m);
    friend class matrixhelper;
    friend ostream& operator<<(ostream& os, const matrix2x2& m);
};

class matrixhelper {
public:
    void updateelement(matrix2x2& m, int row, int col, int value) {
        if(row == 0 && col == 0) m.a = value;
        else if(row == 0 && col == 1) m.b = value;
        else if(row == 1 && col == 0) m.c = value;
        else if(row == 1 && col == 1) m.d = value;
    }
};

int determinant(const matrix2x2& m) {
    return m.a * m.d - m.b * m.c;
}

ostream& operator<<(ostream& os, const matrix2x2& m) {
    os << "[" << m.a << " " << m.b << "]\n";
    os << "[" << m.c << " " << m.d << "]";
    return os;
}

int main() {
    matrix2x2 m1(1, 2, 3, 4);
    matrix2x2 m2(5, 6, 7, 8);

    cout << "mohammad burair - 24k-0775" << endl;
    cout << "\nmatrix 1:\n" << m1 << endl;
    cout << "\nmatrix 2:\n" << m2 << endl;

    cout << "\naddition:\n" << m1 + m2 << endl;
    cout << "\nsubtraction:\n" << m1 - m2 << endl;
    cout << "\nmultiplication:\n" << m1 * m2 << endl;

    cout << "\ndeterminant of m1: " << determinant(m1) << endl;

    matrixhelper helper;
    helper.updateelement(m1, 0, 1, 9);
    cout << "\nafter updating m1[0][1]:\n" << m1 << endl;

    return 0;
}
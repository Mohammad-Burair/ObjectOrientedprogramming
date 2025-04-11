#include <iostream>
using namespace std;

class vector2d {
private:
    float x, y;

public:
    vector2d(float a = 0, float b = 0) : x(a), y(b) {}

    vector2d operator+(const vector2d& other) {
        return vector2d(x + other.x, y + other.y);
    }

    vector2d operator-(const vector2d& other) {
        return vector2d(x - other.x, y - other.y);
    }

    vector2d operator*(float scalar) {
        return vector2d(x * scalar, y * scalar);
    }

    friend float dotproduct(const vector2d& v1, const vector2d& v2);
    friend ostream& operator<<(ostream& os, const vector2d& v);
};

float dotproduct(const vector2d& v1, const vector2d& v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

ostream& operator<<(ostream& os, const vector2d& v) {
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}

int main() {
    vector2d v1(3.5, 2.1);
    vector2d v2(1.2, 4.7);

    cout << "mohammad burair - 24k-0775" << endl;
    cout << "initial vectors:" << endl;
    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;

    vector2d sum = v1 + v2;
    vector2d diff = v1 - v2;
    vector2d scaled = v1 * 2.5f;

    cout << "\noperations:" << endl;
    cout << "v1 + v2 = " << sum << endl;
    cout << "v1 - v2 = " << diff << endl;
    cout << "v1 * 2.5 = " << scaled << endl;

    float dp = dotproduct(v1, v2);
    cout << "dot product of v1 and v2 = " << dp << endl;

    return 0;
}
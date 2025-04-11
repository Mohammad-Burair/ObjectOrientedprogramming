#include<iostream>
#include<string>
#include<cstring>
#include<cmath>

using namespace std;

class Complex{
    int real;
    int imag;
public:
    friend int magnitude(Complex);
    friend Complex operator+(Complex , Complex);
    friend Complex operator-(Complex , Complex);
    friend Complex operator*(Complex , Complex);
    friend Complex operator/(Complex , Complex);
    friend ostream& operator<<(ostream& out, const Complex&);

    Complex (int r , int i){
        real = r;
        imag = i;
    }
    
};

int magnitude(Complex c){
    return sqrt(c.real*c.real + c.imag*c.imag);
}

Complex operator+(Complex c1 , Complex c2){
    Complex c3(c1.real+c2.real , c1.imag+c2.imag);
    return c3;
}

Complex operator-(Complex c1 , Complex c2){
    Complex c3(c1.real-c2.real , c1.imag-c2.imag);
    return c3;
}

Complex operator*(Complex c1 , Complex c2){
    Complex c3((c1.real*c2.real - c1.imag*c2.imag) , (c1.real*c2.imag + c1.imag*c2.real));
    return c3;
}

Complex operator/(Complex c1 , Complex c2){
    Complex c3(((c1.real*c2.real - c1.imag*c2.imag)/magnitude(c2)) , ((c1.imag*c2.real - c1.real*c2.imag)/magnitude(c2)));
    return c3;
}

ostream& operator<<(ostream& out, const Complex& c) {
    out << "(" << c.real << " + " << c.imag << "i)";
    return out;
}

int main(){
    Complex c1(3, 4);
    Complex c2(1, 2);

    Complex c3 = c1 + c2;
    cout<<c3;

    Complex c4 = c1 - c2;
    cout<<c4;

    Complex c5 = c1 * c2;
    cout<<c5;

    Complex c6 = c1 / c2;
    cout<<c6;
    
    return 0;
}

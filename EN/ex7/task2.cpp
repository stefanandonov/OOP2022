//
// Created by Stefan Andonov on 4/15/22.
//
#include<iostream>

using namespace std;

class ComplexNumber {
private:
    double real;
    double imaginary;
public:
    ComplexNumber(double real = 0.0, double imaginary = 0.0) { //2 in 1 constructor
        this->real = real;
        this->imaginary = imaginary;
    }

    friend istream &operator>>(istream &in, ComplexNumber &c) {
        in >> c.real >> c.imaginary;
        return in;
    }

    friend ostream &operator<<(ostream &out, const ComplexNumber &c) {
        if (c.imaginary >= 0) {
            out << c.real << "+" << c.imaginary << "i" << endl;
        } else {
            out << c.real << c.imaginary << "i" << endl;
        }
        return out;
    }

    ComplexNumber operator+(ComplexNumber &c) {
        return ComplexNumber(this->real + c.real, this->imaginary + c.imaginary);
    }

    ComplexNumber &operator+=(ComplexNumber &c) {
        this->real += c.real;
        this->imaginary += c.imaginary;
        return *this;
    }
};


int main() {
    ComplexNumber c;
    cin >> c;
    cout << c;
    ComplexNumber c1;
    cin >> c1;
    cout << c1;

    cout << (c + c1);
    cout << "-------" << endl;
    cout << (c += c1);
    cout << c << c1;
    return 0;
}

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>

class Complex {
    double real_part;
    double imaginary_part;
    
 public:
    Complex(double real = 0, double imaginary = 0) : real_part{real}, imaginary_part{imaginary} {}
    
    double real() const { return real_part; }
    double imaginary() const { return imaginary_part; }

    Complex& operator+=(const Complex& rhs);

    // [optional] TODO(student): declare operators: -=, *=, /=
    Complex& operator-=(const Complex& rhs);
    Complex& operator*=(const Complex& rhs);
    Complex& operator/=(const Complex& rhs);
};

bool operator==(const Complex& lhs, const Complex& rhs);

Complex operator+(Complex lhs, const Complex& rhs);

// TODO(student): declare operators: -, *, /
Complex operator-(Complex lhs, const Complex& rhs);
Complex operator*(Complex lhs, const Complex& rhs);
Complex operator/(Complex lhs, const Complex& rhs);

// TODO(student): declare overloaded ostream insertion operator
std::ostream& operator<<(std::ostream& os, const Complex& o);

#endif  // FUNCTIONS_H
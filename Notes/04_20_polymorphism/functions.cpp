#include "functions.h"

#ifndef debug
#define debug(x) cout << "[DEBUG] (" << __FILE__ << ":" << __FUNCTION__ << ":" << __LINE__ << ") " << #x << " := " << (x) << endl;
#endif

/*
TODO(student): define complex number operators: ==, +, -, *, /, and overloaded ostream insertion
x == y: (a + bi) == (c + di) = true if a == c and b == d
x + y: (a + bi) + (c + di) = (a + c) + (b + d)i
x - y: (a + bi) - (c - di) = (a - c) + (b - d)i
x * y: (a + bi) * (c + di) = (ac - bd) + (ad + bc)i
x / y: (a + bi) / (c + di) = ((a + bi)(c - di)) / ((c + di)(c - di)) = ((ac + bd) + (bc - ad)i) / (c^2 + d^2) = (ac + bd) / (c^2 + d^2) + ((bc - ad) / (c^2 + d^2))i
os << x; --> 0 / a / bi / a + bi / a - bi
*/

bool operator==(const Complex& lhs, const Complex& rhs) {   // <-- don't forget to give the parameters names
    // TODO(student): complete the definition of this method
    return lhs.real() == rhs.real() && lhs.imaginary() == rhs.imaginary();
    //return false;
}

Complex& Complex::operator+=(const Complex& rhs) {  // <-- don't forget to give the parameter a name
    // TODO(student): complete the definition of this method
    this->real_part += rhs.real_part;
    this->imaginary_part += rhs.imaginary_part;
    return *this;
}
Complex& Complex::operator-=(const Complex& rhs) {  // <-- don't forget to give the parameter a name
    // TODO(student): complete the definition of this method
    this->real_part -= rhs.real_part;
    this->imaginary_part -= rhs.imaginary_part;
    return *this;
}
Complex& Complex::operator*=(const Complex& rhs) {  // <-- don't forget to give the parameter a name
    // TODO(student): complete the definition of this method
    this->real_part *= rhs.real_part;
    this->imaginary_part *= rhs.imaginary_part;
    return *this;
}
Complex& Complex::operator/=(const Complex& rhs) {  // <-- don't forget to give the parameter a name
    // TODO(student): complete the definition of this method
    this->real_part /= rhs.real_part;
    this->imaginary_part /= rhs.imaginary_part;
    return *this;
}

Complex operator+(Complex lhs, const Complex& rhs) { return lhs += rhs; }
Complex operator-(/*const*/ Complex/*&*/ lhs, const Complex& rhs) { return lhs -= rhs; }
Complex operator*(Complex lhs, const Complex& rhs) { return lhs *= rhs; }
Complex operator/(Complex lhs, const Complex& rhs) { return lhs /= rhs; }

std::ostream& operator<<(std::ostream& os, const Complex& c) {
    if (c.imaginary() < 0){
        if (c.real() == 0){
            if (c.imaginary() == -1){
                return os << "-i";
            }
            return os << c.imaginary() << "i";
        }
        return os << c.real() << " - " << c.imaginary() << "i";
    }
    // if (c.imaginary() > 0){
    //     return os << c.real() << " + " << c.imaginary() << "i";
    // }
    return os << c.real() << " + " << c.imaginary() << "i";
}
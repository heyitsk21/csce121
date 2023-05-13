/*
adhoc polymorphism = method overloading
subtype polymorphism = use derived objects as a parent object
parametric polymorphism = templetes


target tasks for today:
    * review polymorphism
        + parametric (templates)

    * get ica starter code from https://github.tamu.edu/pcr/csce-12x-spring22

    * can you identify all the polymorphisms used in this code?

    * take the polymorphism ICA quiz: https://docs.google.com/forms/d/e/1FAIpQLSf4mqvzjXWuH8LCGU9meniN-dV3AsqTDZH--qzuEVKaROfu9Q/viewform?usp=sf_link

    * if time permits, practice your polymorphic programming skills by templating your linked list (ICAs from 6 Apr - 18 April)
*/

#ifndef debug
#define debug(x) cout << "[DEBUG] (" << __FILE__ << ":" << __FUNCTION__ << ":" << __LINE__ << ") " << #x << " := " << (x) << endl;
#endif

#define here cout << __FUNCTION__ << ":" << __LINE__ << endl;

#include <iostream>
#include <array>

using std::cout, std::endl;

// recall this example of ad-hoc polymorphism

class Object {
    int x;

 public:
    Object(int x=0) : x{x} {}

    int get_x() const { return x; }
};

Object operator+(const Object&  lhs, const Object& rhs) {
    return Object(lhs.get_x() + rhs.get_x());
}

std::ostream& operator<<(std::ostream& os, const Object& o) {
    return os << o.get_x();
}

int plus(int a, int b)
    { here; return a + b; }

std::string plus(const std::string& a, const std::string& b)
    { here; return a + b; }

double plus(double a, double b)
    { here; return a + b; }

Object plus(const Object& a, const Object& b)
    { here; return a + b; }


// it just so happens that all the functions do the same thing inside.
//   ad-hoc polymorphism allows us to do completely different things, if we want.

// parametric polymorphism (i.e. templates) lets us abstract situations like this
//   situations like having a function with the same name that does the same thing to different types

template <typename T>
T plus(const T& a, const T& b)
    { here; 
    return a + b; }

// this one templated method can be used by the compiler to write all 4 of the above functions (plus any other version we might use) at compile time.

class SubObject : public Object {

 public:
    SubObject(int x=0) : Object(x) {}
    SubObject(const Object& o) : Object(o.get_x()) {} // subtyping polymorphism
};

class Quaternion {
    double a, b, c, d;

 public:
    Quaternion(double a=0, double b=0, double c=0, double d=0) : a{a}, b{b}, c{c}, d{d} {}
    Quaternion(double a, std::array<double, 3> v) : Quaternion(a,v[0],v[1],v[2]) {}

    double scalar_part() const { return a; }
    std::array<double, 3> vector_part() const { return std::array<double, 3>{b,c,d}; }
};


template <typename T, size_t N>
std::array<T,N> componentwise_addition(const std::array<T,N>& lhs, const std::array<T,N>& rhs) {
    std::array<T,N> result;
    for (size_t i = 0; i < N; i++) result[i] = lhs[i] + rhs[i];
    return result;
}

Quaternion operator+(const Quaternion& lhs, const Quaternion& rhs) {
    return Quaternion(lhs.scalar_part() + rhs.scalar_part(), componentwise_addition(lhs.vector_part(), rhs.vector_part()));
}

std::ostream& operator<<(std::ostream& os, const Quaternion& q) {
    std::array<double, 3> v = q.vector_part();
    os << q.scalar_part();
    os << " + " << v[0] << "i";
    os << " + " << v[1] << "j";
    os << " + " << v[2] << "k";
    return os;
}

std::string operator""_s(const char* str, size_t) {
    return std::string(str);
}

int main() {
    debug(plus(1, 2));
    debug(plus("1"_s,"2"_s));
    debug(plus(1.2, 3.4));

    Object ObjectA(1);
    Object ObjectB(2);
    debug(plus(ObjectA, ObjectB));

    SubObject SubObjectA(1);
    SubObject SubObjectB(2);
    debug(plus(SubObjectA, SubObjectB));

    Quaternion QuaternionA(1,2,3,4);
    Quaternion QuaternionB(5,6,7,8);
    debug(plus(QuaternionA, QuaternionB));
    return 0;
}
/* 
C++ STL arrays
    https://en.cppreference.com/w/cpp/container/array
    declare, define, initialize
    access
        operator[]
        .at()
    traverse
        traditional (C-style)
        range-based for ("for each")
    as function parameter
*/

#include <iostream>
#include <array>

#define unless(condition) if (!(condition))

using std::cout, std::endl, std::array;


template <typename Array> //works for any iterable type //parametric polymorphism
void print(const Array& arr, std::ostream& os = cout) {
    os << "[";
    bool first = true;
    for (typename Array::value_type i : arr) {
        unless (first) os << ", ";
        os << i;
        first = false;
    }
    os << "]";
}

template <typename T, size_t N>
std::ostream& operator<<(std::ostream& os, const array<T,N>& a) {
    print(a, os);
    return os;
}

int main() {
    array<int, 7> a = {8,6,7,5,3,0,9};  //you MUST specify "array<type, size> name" = {}; //size must be int literal or const
    cout << "a.size() := " << a.size() << endl;
    //cout << "a.N := " << a.N << endl; //THIS DOESN'T WORK. USE .size()!!!
    cout << "a.at(2) := " << a.at(2) << endl;
    cout << "a[3] := " << a[3] << endl;
    cout << "a.front() := " << a.front() << endl;
    cout << "a.back() := " << a.back() << endl;
    print(a);
    cout << endl;
    cout << a << endl;

    array<std::string, 2> b = {"HELLO", "world"};
    print(b);
    cout << endl;
    cout << b << endl;
}
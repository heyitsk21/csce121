#include <iostream>
#include "ica.h"

#ifndef debug
#define debug(x) cout << "[DEBUG] (" << __FILE__ << ":" << __FUNCTION__ << ":" << __LINE__ << ") " << #x << " := " << (x) << endl;
#endif

#define here cout << __FUNCTION__ << ":" << __LINE__ << endl;\

using std::cout, std::endl, std::cin;

std::string operator*(const std::string& str, size_t n) {
    std::string s;
    for (size_t i = 0; i < n; i++) s += str;
    return s;
}

std::string operator""_s(const char* str, size_t) { return std::string(str); }

std::string indent_str(size_t n) { return " "_s*n; }

unsigned factorial_trace(unsigned n, size_t depth) {
    // TODO(student): read and understand this example
    std::string indent = indent_str(depth);
    cout << indent << n << "!" << endl;

    // base case (by exclusion): 0! = 1! = 1
    unsigned f = 1;
    // recursive step: n! = n*(n-1)!
    if (n > 1) f = n * factorial_trace(n-1, depth+1);

    cout << indent << "= " << f << endl;

    return f;
}

size_t binary_search_trace(const std::vector<int>& v, const int& key, size_t begin, size_t end, size_t depth) {
    // TODO(student)
    // base case: begin >= end => not found
    // recursive step:
    //   if key < middle value => search left half
    //   else if key > middle value => search right half
    //   else return middle index
    return -1;
}

unsigned fibonacci_trace(int n, size_t depth) {
    // TODO(student)
    // base case: f(0) = 0, f(1) = 1
    // recursive step: f(n) = f(n-2) + f(n-1)
    return -1;
}

void hanoi(unsigned n, char src, char dest, char aux) {
    // TODO(student)
    // base case: n = 0 => do nothing
    // recursive step:
    //   move n-1 disks from src to aux using dest
    //   move disk n from src to dest
    //   move n-1 disks from aux to dest using src
}
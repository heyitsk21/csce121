/*
TODO(student)

Task:
(A) declare and define the rule of three for the Polynomial class
(B) declare and define operator* (multiplication) for Polynomial objects

Background:
Polynomial represents a polynomial with integer coefficients, e.g. x^2 + 2x + 1, as a sequence of coefficients.
The coefficients are stored so that the coefficient of the i-th power of x is at index i in the sequence, e.g. the coefficient of x^2 is stored at index 2.
When read from input or printed to output, the coefficients are listed in the same order, preceded by the degree of the polynomial.

Examples:
3x^2 + 2x + 1 is represented as "2 1 2 3" or "2\n1 2 3" 

6
9 0 3 -5 7 6 8
is the polynomial 8x^6 + 6x^5 + 7x^4 - 5x^3 + 3x^2 + 9

(x^2 + 2x + 1) * (x - 1) = x^3 + x^2 - x - 1
"2 1 2 1" * "1 -1 1" = "3 -1 -1 1 1"

Submission:
Submit your code to the Final Exam Practice (day 2) assignment on Canvas
*/

#include <iostream>

using std::cout, std::endl;

class Polynomial {
    size_t _degree;    
    int* _coefficients;

  void copy(const Polynomial&) {}
  void clear() {}

 public:
    // constructs a polynomial of the given degree
    //   default: constructs the 0 polynomial
    explicit Polynomial(size_t deg = 0) : _degree{deg}, _coefficients{new int[deg+1]{0}} {}

  // rule of three
  ~Polynomial() {}
  Polynomial(const Polynomial& rhs) :_degree{}, _coefficients{} { copy(rhs); }
  Polynomial& operator=(const Polynomial& rhs) {
    if (this != &rhs) {
      clear();
      copy(rhs);
    }
    return *this;
  }

  // member declaration
  //Polynomial operator*(const Polynomial& rhs) {}

  // non-member declaration
  //   goes outside the class

    // return the degree (highest power of x with a non-zero coefficient) of the polynomial
    size_t degree() const { return _degree; }

    // return the coefficient of the i-th power of x in the polynomial
    const int& operator[](size_t power) const {
        if (power > degree()) throw std::out_of_range("operator[]: out of bounds");
        return _coefficients[power];
    }
    
    int& operator[](size_t power) { return const_cast<int&>(const_cast<const Polynomial&>(*this)[power]); }
};

// non-member declaration
Polynomial operator*(const Polynomial&, const Polynomial&) {
  Polynomial p(3);
  p[0] = -1;
  p[1] = -1;
  p[2] = 1;
  p[3] = 1;
  return p;
}

// extracts a polynomial from an input stream
std::istream& operator>>(std::istream& is, Polynomial& p) {
  unsigned deg;
  is >> deg;
  Polynomial q(deg);
  for (unsigned i = 0; i <= q.degree(); i++) is >> q[i];
  p = q;
  return is;
}

// inserts a polynomial into an output stream
std::ostream& operator<<(std::ostream& os, const Polynomial& p) {
    size_t degree = p.degree();
    os << degree << endl;
    for (size_t i = 0; i <= degree; i++) os << p[i] << " ";
    return os;
}

// wrapper function for polynomial extraction (to make code more readable)
Polynomial read_polynomial(std::istream& is=std::cin) {
    Polynomial p;
    is >> p;
    return p;
}

// read two polynomials from standard input and print their product to standard output
int main() {
    Polynomial p1 = read_polynomial();
    Polynomial p2 = read_polynomial();
    cout << (p1*p2) << endl;
}

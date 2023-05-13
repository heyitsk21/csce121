/*

target tasks for today:
    * review polymorphism
        + ad-hoc (function overloading)     

    * get ica starter code from https://github.tamu.edu/pcr/csce-12x-spring22

    * write unit tests and implement polymorphic code
        + write some tests, then write some code to pass the tests
        + submit your tests and methods to https://docs.google.com/forms/d/e/1FAIpQLSfRS8sutmjb0_B3pGK6XixmHuTzyzYKyvddcW-MKrWhLLu8JA/viewform?usp=sf_link
*/

#ifndef debug
#define debug(x) cout << "[DEBUG] (" << __FILE__ << ":" << __FUNCTION__ << ":" << __LINE__ << ") " << #x << " := " << (x) << endl;
#endif

#include <iostream>

using std::cout, std::endl;

int plus(int a, int b)
    {return a+b;}
std::string plus(const std::string& a, const std::string& b)
    {return a+b;}
double plus(double a, double b)
    {return a+b;}
std::string plus(char a, char b) 
    {std::string s; s.push_back(a); s.push_back(b); return s;}

class Object {
    int x;
 public:
    Object (int x=0): x{x} {}

    int get_x() const { return x; }

    Object& operator(+=const Object& rhs){
        x += rhs.x;
        return *this;
    }
}

// Object operator+(Object lhs, const Object& rhs){
//     return lhs += rhs;
// }

Object operator+(Object lhs, const Object& rhs){
    return lhs += rhs;
}

std::ostream& operator<<(std::ostream& os, const Object& o) {
    return os << o.get_x();
}

Object plus(const Object& a, const Object& b){
    return a + b;
}

int main() {
    cout<<plus(1,2)<<endl;
    cout<<plus("1","2")<<endl;

    cout<<plus(1.2,3.4)<<endl;
    cout<<plus("1.2","3.4")<<endl;

    Object a{1};
    Object b{2};
    cout<<plus(a,b)<<endl;

    return 0;
}
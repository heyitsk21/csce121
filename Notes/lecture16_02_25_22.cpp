/*
* polymorphism
    + ad-hoc: function overloading
        - operator overloading
            * overloading ostream insertion operator (operator<<)
    + parametric: templates
    + subtyping
*/

#include <iostream>
#include <string>
#include <typeinfo>

using std::cout, std::endl, std::string;

struct Person {
    string name;
    int age;
};

// ad-hoc polymorphism: function overloading
string operator*(const string& lhs, unsigned int rhs) {
    string ret;
    while (rhs > 0) {
        ret += lhs;
        rhs--;
    }
    return ret;
}

string operator+(const string& lhs, int rhs) {
    return lhs + std::to_string(rhs);
}

std::ostream& operator<<(std::ostream& os, const std::exception& err) {
    os << typeid(err).name() << ": " << err.what() << endl;
    return os;
}

std::ostream& operator<<(std::ostream& os, const Person& p) {
    os << p.name << " is " << p.age << " years old";
    return os;
}

void polymorphism_ad_hoc_example() {
    string str = "howdy ";
    cout << str*3 << endl;
    
    cout << str + -7 << endl;
    
    cout << std::logic_error("OK!") << endl;
    
    Person ritchey{"prof. ritchey", 36};
    cout << ritchey << endl;
}


// parametric polymorphism: templates
template <typename TYPE, size_t SIZE>
struct Array {
    TYPE A[SIZE];  // e.g. "int A[12]"
    
    size_t size() { return SIZE; }
    TYPE& at(size_t index) {
        if (index >= SIZE) {
            throw std::out_of_range("Array::at("+std::to_string(index)+"): index out of bounds");
        }
        return A[index];
    }
    
    typedef TYPE* iterator;
    iterator begin() { return &A[0]; }
    iterator end() { return &A[SIZE]; }
};

void polymorphism_parametric_example() {
    Array<Person, 6> csce12x_instructors = {
        Person{"moore", 1000},
        Person{"mcguire", 1010},
        Person{"huang", 24},
        Person{"taele", 35},
        Person{"ritchey", 100},
        Person{"carlisle", 40}
    };
    
    for (const Person& person : csce12x_instructors) {
        //cout << person.name << " " << person.age << endl;
        cout << person << endl;
    }
    
    Array<int, 7> jennys_phone_number = {8,6,7,5,3,0,9};
    for (int digit : jennys_phone_number) {
        cout << digit;
    }
    cout << endl;
}

// subtyping
struct Student : public Person {
    // Person attributes, too
    int UIN;
};

struct CS12xStudent : public Student {
    int section;
};

std::ostream& operator<<(std::ostream& os, const Student& s) {
    os << s.name << " is a student and is " << s.age << " years old";
    return os;
}

void shout_out(const Person& person) {
    cout << "Hey! " << person << "!" << endl;
}



void polymorphism_subtyping_example() {
    Person person = {"person", 7};
    Student student = {"student", 18, 123006789};
    CS12xStudent programmer = {"awesome student", 19, 321002023, 591};
    shout_out(person);
    shout_out(student);    // note _NOT_ inheritance
    shout_out(programmer); // note _NOT_ inheritance
    cout << programmer << endl;  // ad-hoc
}

int main() {
    polymorphism_ad_hoc_example();
    //polymorphism_parametric_example();
    //polymorphism_subtyping_example();
    
    return 0;
}
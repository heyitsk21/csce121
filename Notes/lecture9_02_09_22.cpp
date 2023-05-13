//02-09-22

/* agenda
    object-oriented concepts
        inheritance
        polymorphism
    io streams as an example of OOP
        encapsulation - https://en.cppreference.com/w/cpp/header/ios
        inheritance - https://en.cppreference.com/w/cpp/io#Stream-based_I.2FO
        polymorphism - e.g. https://en.cppreference.com/w/cpp/string/basic_string/getline 
*/

/* encapsulation
    {data, methods} - bundle data and methods together into one thing

    string: {
        data:
            array of characters
            number of characters / length of string
            
        methods:
            length() - return length of string
            at(index) - return character at given index
            find(string) - return first index of string in this string, or -1 (npos) if not found
            ...
    }
*/

/* inheritance
    children inherit traits from parents
    subclasses "inherit" properties/attributes/members (data and methods) from superclasses
        can directly access public and protected members
        cannot directly access private members
    children can do more and different than parents
        can (with parental approval) override parent methods
*/

/* polymorphism
    1) ad-hoc - function overloading - many functions, same name, different parameter lists
    foo(int i) {}
    foo(double d) {}
    foo(char*) {}
    foo(std::string) {}
    foo(UserDefinedObject) {}
    foo(int i1, int i2) {}
    each foo() can do a different thing.
    2) parameterized - templates - write one function/class template (blueprint), the compiler uses that blueprint to create (at compile time) the actual definitions of the function/class for the specified type.
    template <typename T>
    void foo(T thing) {
        cout << thing << endl;
    }
    foo(7); // int
    foo(7.0); // double
    foo("cstring"); // c-string
    foo(std::string("c++ string")); 
    foo(UserDefinedObjectThatHasOperatorOstreamInsertDefined());
    one foo does the same thing to all types
    3) subtyping - subclasses / inheritance - "a cat 'is a' animal"
        subclass instances are also instances of the parent class
    
    any method which works with a parent object must also work with a child object (liskov substitution principle).
*/

#include <iostream>
#include <string>

using std::cin, std::cout, std::endl;
using std::string;

class Animal {
    private:
    // canNOT be directly accessed by any
    int secret;
    
    protected:
    // can be accessed by subclasses
    string name;

    int get_secret() { return secret; }
    
    public:
    // can be accessed by all
    Animal() : secret{42}, name{"buster"} {
        cout << "i'm an animal!" << endl;
    }
    virtual ~Animal() {}
    string get_name() const { return name; }

    virtual void talk() const { cout << "<strange animal noises>" << endl; } //VIRTUAL will let the Cat's "talk()" override Animal's "talk()" function. Cat's "talk()" can say OVERRIDE. if Animal not VIRTUAL, OVERRIDE will cause an compiler error
};

class Cat : public Animal {
    public:
    Cat() {
        cout << "i'm a cat!" << endl;
        // cannot directly access private members of parent class
        // cout << secret << endl;
        
        // can access protected members of parent class
        cout << get_secret() << endl; 
    }

    void rename(string new_name) {
        // every cat has a name data attribute because every cat is an Animal
        name = new_name;
    }

    void talk() const override { cout << "meow" << endl; } //OVERRIDEs the Animal's "talk()" function... which was VIRTUAL
};

void talk_to_animal(const Animal& animal) {
    cout << "you: hello, what's your name!?" << endl;
    cout << "animal: " << animal.get_name() << " ";
    animal.talk();
    cout << endl;
}

int main() {
    Cat cat;
    cat.rename("hemi");
    // inheritance
    // every cat has a get_name() method because every cat is an Animal
    cout << cat.get_name() << endl;
    
    // polymorphism
    talk_to_animal(cat);

    Animal animal;
    talk_to_animal(animal);

    return 0;
}
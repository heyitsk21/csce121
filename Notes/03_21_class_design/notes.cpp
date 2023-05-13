/*
    Classes
        Access Modifiers
            public
            protected
            private
        Attribute Accessors
            getters
            setters
        Constructors
            default
            parameterized
            explicit
        this
*/

#include <iostream>

#define PRINT(X) cout<<#X<<" := "<<(X)<<endl;

using std::cout, std::endl;

class A {
    // class members are private by default
    std::string private_value;

    void private_method() {
        PRINT(__FUNCTION__);
        PRINT(private_value);
        PRINT(protected_value);
        PRINT(public_value);
    }

    protected:
    // can be accessed by other As and children of A
    std::string protected_value;

    void protected_method() {
        PRINT(__FUNCTION__);
        PRINT(private_value);
        PRINT(protected_value);
        PRINT(public_value);
    }

    void set_private_value(const std::string& new_value) {
        this->private_value = new_value;
    }

    std::string get_private_value() {
        return private_value;
    }

    public:
    // can be accessed by anyone
    std::string public_value;

    void public_method() {
        PRINT(__FUNCTION__);
        PRINT(private_value);
        PRINT(protected_value);
        PRINT(public_value);
    }

    const A* get_this() const {
        return this;
    }

    // default constructor has no arguments
    A() : private_value{"private in A"}, protected_value{"protected in A"}, public_value{"public in A"} {}

    // parameterized constructor has arguments
    A(const std::string& priv, const std::string& prot, const std::string& pub) : private_value{priv}, protected_value{prot}, public_value{pub} {}

    // explicit constructor is parameterized constructor (typically with 1 arg) that does not particiapte in implicit conversion
    //   "explicit" is useful when you have a 1-arg constrcutor and you want to protect against unintended attempts at (implicit) conversion
    //   --> does NOT allow for conversion
    explicit A(const std::string& str) : A(str,str,str) {}

    // implicit conversion constructor
    A(int n) : A(std::to_string(-n), "0", std::to_string(n)) {}
};

// B inherits from A without [further] restricting access
//   access can only be narrowed by inheritance, never widened
class B : public A {
    // class members are private by default
    std::string private_value;

    void private_method() {
        PRINT(__FUNCTION__);
        PRINT(private_value);
        PRINT(protected_value);
        PRINT(public_value);
        //PRINT(A::private_value);
        PRINT(A::protected_value);
        PRINT(A::public_value);
    }

    protected:
    // can be accessed by other Bs and children of B
    std::string protected_value;

    void protected_method() {
        PRINT(__FUNCTION__);
        PRINT(private_value);
        PRINT(protected_value);
        PRINT(public_value);
        //PRINT(A::private_value);
        PRINT(A::protected_value);
        PRINT(A::public_value);
    }

    public:
    // can be accessed by anyone
    std::string public_value;

    // about the only good example of a public data member
    const int SOME_CONSTANT = 3;

    void public_method() {
        PRINT(__FUNCTION__);
        PRINT(private_value);
        PRINT(protected_value);
        PRINT(public_value);
        //PRINT(A::private_value);
        PRINT(A::protected_value);
        PRINT(A::public_value);
    }

    //SETTER
    void set_private_value(const std::string& new_value) {
        // e.g. do input validation here (and refuse to input the value if invalid)
        this->private_value = new_value;
    }

    //SETTER
    void set_private_A_value(const std::string& new_value) {
        A::set_private_value(new_value);
    }

    //GETTER
    std::string get_private_A_value() {
        return A::get_private_value();
    }

    // default constructors has no arguments
    B() : private_value{"private in B"}, protected_value{"protected in B"}, public_value{"public in B"} {}
};

class C {
    int _value;

public:
    C() : _value{} {}

    // "setter" (but can also get)
    int& value() { return _value; }
    // "getter" (cannot set)
    int value() const { return value(); }
};

int main() {
    A a;
    B b;

    cout << "print data members of a" << endl;
    //PRINT(a.private_value);   // not accessible from outside of class
    //PRINT(a.protected_value); // not accessible from outoutsidesdie of class
    PRINT(a.public_value);
    cout << endl;

    cout << "invoke method members of a" << endl;
    //a.private_method();
    //a.protected_method(); // not accessible from outside of class
    a.public_method();
    cout << endl;

    cout << "print data members of b" << endl;
    //PRINT(b.private_value);   // not accessible from outside of class
    //PRINT(b.protected_value); // not accessible from outside of class
    PRINT(b.public_value);
    cout << endl;

    cout << "print data members of b inherited from A" << endl;
    //PRINT(b.A::private_value);    // not accessible from outside of class
    //PRINT(b.A::protected_value);  // not accessible from outside of class
    PRINT(b.A::public_value);
    cout << endl;

    cout << "invoke method members of b" << endl;
    //b.private_method();   // not accessible from outside of class
    //b.protected_method(); // not accessible from outside of class
    b.public_method();
    cout << endl;

    cout << "invoke method members of b inherited from A" << endl;
    //b.A::private_method();   // not accessible from outside of class
    //b.A::protected_method(); // not accessible from outside of class
    b.A::public_method();
    cout << endl;

    cout << "modify public data members" << endl;
    // private and protected are not accessible from here
    a.public_value = "modified public value in A";
    b.public_value = "modified public value in B";
    b.A::public_value = "modifed public value in A through B";
    a.public_method();
    b.public_method();
    b.A::public_method();
    cout << endl;

    cout << "use accessors to modify private data members" << endl;
    b.set_private_value("modified private value in B");
    b.set_private_A_value("modified private value in A through B");
    b.public_method();
    PRINT(b.get_private_A_value());
    cout << endl;

    cout << "use different constructor types" << endl;
    {
        cout << "default" << endl;
        A a;
        a.public_method();
        cout << endl;
    }
    {
        cout << "parameterized" << endl;
        A a("one", "two", "three");
        a.public_method();
        cout << endl;
    }
    {
        cout << "explicit 1-arg parameterized" << endl;
        A a("all the same");
        a.public_method();
        cout << endl;
    }
    {
        // this won't work because the only constructor that matches is declared explicit
        /*
        cout << "explicit 1-arg parameterized" << endl;
        A a = "all the same";
        a.public_method();
        cout << endl;
        */
    }
    {
        cout << "implicit converting constructor" << endl;
        A a = 7;
        a.public_method();
        cout << endl;
    }

    cout << "A's this" << endl;
    PRINT(&a); // a reference to the address of the object
    PRINT(a.get_this());

    cout << "fancy accessors" << endl;
    C c;
    PRINT(c.value());
    c.value() = 7;
    PRINT(c.value());

    return 0;
}
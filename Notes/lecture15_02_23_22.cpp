/*
* memory diagrams
    + stack frame
    + references & pointers
    + arrays & structs
* functions
    + pass by reference
    + command line arguments
    + default parameters
*/

#include <iostream>
#include <string>
#include <array>

#define DEBUG(X) std::cout<<"[DEBUG] ("<<__FUNCTION__<<":"<<__LINE__<<") "<<#X<<" := "<<(X)<<std::endl;
#define HERE std::cout<<"[HERE] "<<__FILE__<<":"<<__FUNCTION__<<":"<<__LINE__<<std::endl;

using std::cout, std::endl, std::string;

struct Person {
    string name;
    int age;
};

int pbv(int a) {
    DEBUG(a)
    a++;
    DEBUG(a)
    return a;
}

int pbr(int& a) {
    DEBUG(a)
    a++;
    DEBUG(a)
    return a;
}

int pbpv(int* a) {
    DEBUG(a)
    DEBUG(*a)
    (*a)++;
    DEBUG(a)
    DEBUG(*a)
    a++;
    DEBUG(a)
    DEBUG(*a)
    return *a;
}

void pbv(int a[]) {
    DEBUG(a)
    DEBUG(a[0])
    a[0]++;
    DEBUG(a)
    DEBUG(a[0])
}

void pbr(int (&a)[3]) {
    DEBUG(a)
    DEBUG(a[0])
    a[0]++;
    DEBUG(a)
    DEBUG(a[0])
}

void pbpv(int (*a)[3]) {
    DEBUG(a)
    DEBUG(a[0])
    DEBUG((*a)[0])
    (*a)[0]++;
    DEBUG(a)
    DEBUG(a[0])
    DEBUG((*a)[0])
    a++;
    DEBUG(a)
    DEBUG(a[0])
    DEBUG((*a)[0])
}

void pbv(Person p) {
    DEBUG(p.age)
    p.age++;
    DEBUG(p.age)
}

void pbr(Person& p) {
    DEBUG(p.age)
    p.age++;
    DEBUG(p.age)
}

void pbpv(Person* p) {
    DEBUG(p)
    DEBUG(p->age) 
    (*p).age++;
    DEBUG(p)
    DEBUG(p->age) 
    p++;
    DEBUG(p)
    DEBUG(p->age) 
}

void memory_diagram_example() {
    int x = 5;
    DEBUG(x)
    int y = pbv(x);
    DEBUG(x)
    DEBUG(y)
    int z = pbr(y);
    DEBUG(x)
    DEBUG(y)
    DEBUG(z)
    DEBUG(&x)
    DEBUG(&y)
    DEBUG(&z)
    x = pbpv(&y);
    DEBUG(x)
    DEBUG(y)
    DEBUG(z)
    
    int A[] = {1,2,3};
    DEBUG(A)
    DEBUG(A[0])
    pbv(A);
    DEBUG(A)
    DEBUG(A[0])
    pbr(A);
    DEBUG(A)
    DEBUG(A[0])
    pbpv(&A);
    DEBUG(A)
    DEBUG(A[0])
    
    Person p{"Alice", 42};
    DEBUG(p.age)
    pbv(p);
    DEBUG(p.age)
    pbr(p);
    DEBUG(p.age)
    pbpv(&p);
    DEBUG(p.age)
}

typedef const char* cstring;

void command_line_arguments_example(int argc, cstring argv[]) {
    cout << argc << " command line arguments:" << endl;
    for (int i = 0; i < argc; i++) {
        cout << "  argv["<<i<<"] = " << argv[i] << endl;
    }
    
    // if you want to get "fancy", look at getopt (https://linux.die.net/man/3/getopt)
}

void default_parameters_example(int x = 12) {
    cout << "x = " << x << endl;
}

int main(int argc, cstring argv[]) {
    memory_diagram_example();
    //command_line_arguments_example(argc, argv);
    //default_parameters_example(7);
    //default_parameters_example();
}
/*
Demo: BFOs on the Stack vs Heap
Memory Diagrams with the Heap
    Allocation
    Deallocation
    Memory Leak
Puzzle
*/

#include <iostream>

using std::cout, std::endl;

struct Chonk {
    int A[1000][1000][1000];
};

void chonkers() {
    cout << "consider this Absolute Unit of an object:" << endl << endl;
    cout << "    struct Chonk {\n        int A[1000][1000][1000];\n    };" << endl << endl;
    cout << "it requires 4 GB of memory to allocate." << endl << endl;
    
    cout << "it does not fit on the stack." << endl << endl;
    cout << "    Chonk chonk_on_stack;" << endl << endl;
    //Chonk chonk_on_stack;
    cout << "compiles fine.... but at runtime:" << endl << endl;
    cout << "    Segmentation fault (core dumped)" << endl << endl;
    
    cout << "but, it does fit on the heap!" << endl << endl;
    cout << "    Chonk* chonk_on_heap = new Chonk;" << endl;
    Chonk* chonk_on_heap = new Chonk;
    cout << "    sizeof(*chonk_on_heap) := " << sizeof(*chonk_on_heap) << endl << endl;
    
    cout << "this is one benefit of dynamic allocation: we can handle REALLY big objects" << endl;
    
    // pause for effect
    cout << endl << "can you see it in task manager?" << endl;
    std::string line;
    getline(std::cin, line);
    cout << "how about now?" << endl;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            chonk_on_heap->A[i][j][i] = i*j;
        }
    }
    getline(std::cin, line);
    cout << "and... release!" << endl;

    // deallocate the chonk
    delete chonk_on_heap;
}

#include <vector>

std::vector<int> range(int n) {
    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        v.at(i) = i;
    }
    return v;
}

// generate elements of the range "on-demand" (useful for BIG ranges)
class xrange {
    int _start;
    int _end;
    int _step;

    public:
    xrange(int start, int end, int step=1) : _start{start}, _end{end}, _step{step} {
        if (step == 0) {
            throw std::invalid_argument("step size of 0");
        }
        if (end < start && step > 0) {
            throw std::invalid_argument("end < start but step > 0");
        }
    }
    xrange(int end) : xrange(0, end) {}

    bool empty() const { 
        return (_step > 0 && _start >= _end) ||
               (_step < 0 && _start <= _end); 
    }
    
    class const_iterator {
        int current_value;
        int step;

        public:
        const_iterator(int n, int step = 1) : current_value{n}, step{step} {
            if (step == 0) {
                throw std::invalid_argument("step size of 0");
            }
        }

        int operator*() const { 
            return current_value;
        }
        
        const_iterator& operator++() {
            current_value += step;
            return *this;
        }

        bool operator!=(const const_iterator& rhs) const {
            return current_value < rhs.current_value;
        }
    };

    const_iterator begin() const {
        return const_iterator(_start, _step);
    }

    const_iterator end() const {
        return const_iterator(_end);
    }
};

void puzzle() {
    int n = 5;
    int sum = 0;
    while (n > 0) {
        for (int i : xrange(n)) {
            n = i;
            sum += n;
        }
    }
    cout << "sum := " << sum << endl;
    
    // what happens?
    // A. infinite loop
    // B. compiler error
    // C. runtime error
    // D. it works, sum is: ?
    
    // and why?
}

int main() {
    //chonkers();
    puzzle();

    // range(0) returns an empty vector
    auto r = range(0);
    cout << r.empty() << endl;
    for (int i : r) {
        cout << "here" << i << endl;
    }

    auto xr = xrange(0);
    cout << xr.empty() << endl;
    for (int i : xr) {
        cout << "here" << i << endl;
    }

    return 0;
}
/*
n   sum range(n)    i
---------------------
5   0   [0,1,2,3,4] 
0   0               0
1   1               1
2   3               2
3   6               3
4   10              4
- - - - - - - - - - -
        [0,1,2,3]   
0   10              0
1   11              1
2   13              2
3   16              3
- - - - - - - - - - -
        [0,1,2]
0   16              0
1   17              1
2   19              2
- - - - - - - - - - -
        [0,1]
0   19              0
1   20              1
- - - - - - - - - - -
        [0]
0   20              0
- - - - - - - - - - -
sum := 20
*/
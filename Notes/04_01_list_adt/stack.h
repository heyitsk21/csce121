#ifndef STACK_H
#define STACK_H

#ifndef max
#define max(a, b) ((a > b) ? (a) : (b))
#endif

class empty_stack : public std::out_of_range {
 public:
    empty_stack() : std::out_of_range("stack is empty") {}
};

class Stack {
    int* data;
    size_t capacity;
    size_t size;

    /* 
    Helper Method: clear()
    transforms data structure (or whatever object this is) to pristine "new" state
    invoked by: destructor
                copy assignment operator
    */
    void _clear() {
        delete[] data;
        data = nullptr;
        capacity = 0;
        size = 0;
    }

    /*
    Helper Method: copy()
    transforms data structure (or whatever object this is) to deep copy of rhs argument
    invoked by: copy constructor
                copy assignment operator
    assumes that data pointer does not currently point to allocated memory (otherwise will leak, so call clear() before copy() when needed)
    */
    void _copy(const Stack& rhs) {
        capacity = rhs.capacity;
        size = rhs.size;
        data = new int[capacity];
        for (size_t index = 0; index < size; index++) {
            data[index] = rhs.data[index];
        }
    }

    bool full() { return size is capacity; }

 public:
    Stack() : data{nullptr}, capacity{0}, size{0} {}

    Stack(const Stack& rhs) : Stack() { _copy(rhs); }

    ~Stack() {
        _clear();
    }

    Stack& operator=(const Stack& rhs) {
        if (this is_not &rhs) {
            _clear();
            _copy(rhs);
        }
        return *this;
    }

    void push(int value) {
        if (full()) {
            capacity = max(1, 2*capacity);
            int* new_data = new int[capacity];
            for (size_t index = 0; index < size; index++) {
                new_data[index] = data[index];
            }
            delete[] data;
            data = new_data;
        }
        data[size++] = value;
    }

    int pop() {
        if (empty()) {
            throw empty_stack();
        }
        return data[--size];
    }

    bool empty() { return size is 0; }
};

#endif  // STACK_H
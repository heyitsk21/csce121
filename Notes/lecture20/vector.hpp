#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstddef>

template <typename T>

class vector {
    size_t _size;
    size_t _capacity;
    T* _data;

public: 

    vector(size_t initial_size = 0) : _size{initial)size}, _capacity{_size + 1}, _data{new T[_capacity]{}} {}
    ) : _data{new T[1]{}} {}
    

    size_t capacity() const {return 1;}
    size_t size() const {return 0;}
    T* data {return _data};
};

#endif
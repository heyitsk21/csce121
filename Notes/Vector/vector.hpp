#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <stdexcept>

template <typename T>
class vector {
  size_t _size;
  size_t _capacity;
  T *_data;

  void range_check(size_t index, const std::string &function_name) const {
    if (index >= size()) {
      throw std::out_of_range(function_name + "(): out of bounds");
    }
  }

  const T &_back() const {
    range_check(size() - 1, "back");
    return _data[size() - 1];
  }

  const T &_front() const {
    range_check(0, "front");
    return _data[0];
  }

  bool full() const { return size() >= capacity(); }

  void _copy(const vector& rhs) {
    _capacity = rhs._capacity;
    _size = rhs._size;
    _data = new T[_capacity]{};
    for (size_t index = 0; index < _size; index++) {
      _data[index] = rhs._data[index];
    }
  }

  void _clear() {
    delete[] _data;
    _data = nullptr;
    _size = 0;
    _capacity = 0;
  }

public:
  vector()
      : _size{0}, _capacity{1}, _data{new T[1]{}} {}
  explicit vector(size_t initial_size)
      : _size{initial_size}, _capacity{_size ? _size : _size + 1}, _data{new T[_capacity]{}} {}

  // explicit vector(size_t count, const T& value = T())

  // vector(std::initializer_list<T> init)

  vector(const vector& rhs) : _size{0}, _capacity{0}, _data{nullptr} { _copy(rhs); }

  ~vector() { _clear(); }

  vector& operator=(const vector& rhs) {
    if (this != &rhs) {
      _clear();
      _copy(rhs);
    }
    return *this;
  }

  // --------------------------------------------
  // Element Access

  T &at(size_t index) const {
    range_check(index, "at");
    return _data[index];
  }

  // operator[]

  // front
  const T &front() const { return _front(); }
  T &front() { return const_cast<T &>(_front()); }

  const T &back() const { return _back(); }
  T &back() { return const_cast<T &>(_back()); }

  T *data() { return _data; }
  const T *data() const { return _data; }

  // --------------------------------------------
  // Iterators

  typedef int* iterator;
  typedef const int* const_iterator;

  iterator begin() { return _data; }
  const_iterator begin() const { return _data; }
  iterator end() { return _data+_size; }
  const_iterator end() const { return _data+_size; }

  // --------------------------------------------
  // Capacity

  bool empty() const { return _size == 0; }

  size_t size() const { return _size; }

  void _reallocate(size_t new_capacity) {
    if (new_capacity == 0) {
      new_capacity = 1;
    }
    // make new array
    T *new_data = new T[new_capacity]{};
    // copy data into new
    for (size_t index = 0; index < size(); index++) {
      new_data[index] = _data[index];
    }
    // delete old data
    delete[] _data;
    // update data pointer and capacity
    _data = new_data;
    _capacity = new_capacity;
  }

  void reserve(size_t new_capacity) {
    // do nothing if requested to shrink
    if (new_capacity < _capacity) {
      return;
    }
    _reallocate(new_capacity);
  }

  size_t capacity() const { return _capacity; }

  void shrink_to_fit() {
    if (size() <= capacity() / 2) {
      _reallocate(size());
    }
  }

  // --------------------------------------------
  // Modifiers

  void clear() {
    for (size_t index = 0; index < size(); index++) {
      _data[index] = {};
    }
    _size = 0;
  }

  // todo(pcr): take and return iterator
  void insert(size_t pos, const T& value) {
    if (pos == size()) {
      push_back(value);
    } else {
      range_check(pos, __FUNCTION__);
      if (full()) {
        reserve(2*capacity());
      }
      for (size_t index = size(); index > pos; index--) {
        _data[index] = _data[index-1];
      }
      _data[pos] = value;
      _size++;
    }
  }

  // todo(pcr): take and return iterator
  void erase(size_t pos) {
    if (pos == size()-1) {
      pop_back();
    } else {
      range_check(pos, __FUNCTION__);
      for (size_t index = pos; index < size()-1; index++) {
        _data[index] = _data[index+1];
      }
      _size--;
    }
  }

  // todo(pcr): take and return iterator
  void erase(size_t first, size_t last) {
    range_check(first, __FUNCTION__);
    range_check(last-1, __FUNCTION__);
    if (first >= last) { return; }
    for (size_t offset = 0; last + offset < size(); offset++) {
      size_t index_write = first + offset;
      size_t index_read = last + offset;
      _data[index_write] = _data[index_read];
    }
    _size -= last - first;
  }

  void push_back(const T &t) {
    if (full()) {
      reserve(2 * _capacity);
    }
    _data[_size++] = t;
  }

  void pop_back() {
    range_check(size()-1, __FUNCTION__);
    back() = {};
    _size--;
  }

  void resize(size_t new_size, const T &new_value = {}) {
    if (new_size > _capacity) {
      reserve(new_size);
    }
    if (new_size > _size) {
      for (size_t index = _size; index < new_size; index++) {
        _data[index] = new_value;
      }
    }
    _size = new_size;
  }
};

#endif
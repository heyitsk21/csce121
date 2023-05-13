#ifndef LIST_H
#define LIST_H

#include <cstddef>

// abstract (pure virtual) class List
// a sequential collection
// with operations size, at, insert, remove

template <typename T>
class List {
 public:
    virtual size_t size() const = 0;
    virtual const T& at(size_t) const = 0;
    virtual T& at(size_t) = 0;
    virtual void insert(size_t, const T&) = 0;
    virtual void remove(size_t) = 0;
    virtual ~List() {}
};

#endif  // LIST_H